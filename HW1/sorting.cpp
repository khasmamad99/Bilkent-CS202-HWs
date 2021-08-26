/**
* Title : Algorithm Efficiency and Sorting
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 1
* Description : Implementations of bubbleSort, quickSort, mergeSort,
                and radixSort along with performanceAnalysis method
*/

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>
#include <stdio.h>
using namespace std;

#include "sorting.h"

void swapp(int &first, int &second){
    int temp = first;
    first = second;
    second = temp;
}

// The implementation in the slides is used
void bubbleSort(int *arr, int n, int &compCount, int &moveCount){
    bool sorted = false;
    compCount = 0;
    moveCount = 0;

    for (int pass = 1; (pass < n) && !sorted; ++pass) {
        sorted = true;
        for (int index = 0; index < n-pass; ++index) {
            int nextIndex = index + 1;
            compCount++;
            if (arr[index] > arr[nextIndex]) {
                swapp(arr[index], arr[nextIndex]);
                moveCount += 3;
                sorted = false; // signal exchange
            }
        }
    }
}


// The implementation relies on the slides
void quickSort(int *arr, int n, int &compCount, int &moveCount){
    compCount = 0;
    moveCount = 0;
    quickSort(arr, 0, n - 1, compCount, moveCount);
}

void quickSort(int *arr, int first, int last , int &compCount, int &moveCount){
    int pivotIndex;

    if (first < last) {
        partitionn(arr, first, last, pivotIndex, compCount, moveCount);

        quickSort(arr, first, pivotIndex - 1, compCount, moveCount);
        quickSort(arr, pivotIndex + 1, last, compCount, moveCount);
    }
}

void partitionn(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount){
    pivotIndex = first;
    int lastS1 = first;
    int firstUnknown = first + 1;

    for ( ; firstUnknown <= last; firstUnknown++){
        compCount++;
        if (arr[firstUnknown] < arr[pivotIndex]){
            moveCount += 3;
            swapp(arr[lastS1 + 1], arr[firstUnknown]);
            lastS1++;
        }
    }
    swapp(arr[pivotIndex], arr[lastS1]);
    moveCount += 3;
    pivotIndex = lastS1;
}

void mergeSort(int *arr, int n, int &compCount, int &moveCount) {
    compCount = 0;
    moveCount = 0;
    mergeSort(arr, 0, n - 1, compCount, moveCount);
}

// the implementation relies on the slides
void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount){
    if (first < last) {
        int mid = (first + last) / 2;

        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid + 1, last, compCount, moveCount);

        mergee(arr, first, mid, last, compCount, moveCount);
    }
}


void mergee(int *arr, int first, int mid, int last, int &compCount, int &moveCount) {
    int tempArr[last - first + 1];

    int first1 = first;         // beginning of the first subarray
    int last1 = mid;            // end of the first subarray
    int first2 = mid + 1;       // beginning of the second subarray
    int last2 = last;            // end of the second subarray
    int index = 0;              // index of the temp array

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        compCount++;
        moveCount++;
        if (arr[first1] < arr[first2]) {
            tempArr[index] = arr[first1];
            first1++;
        }
        else {
            tempArr[index] = arr[first2];
            first2++;
        }
    }

    for ( ; first1 <= last1; index++, first1++){
        tempArr[index] = arr[first1];
        moveCount++;
    }

    for ( ; first2 <= last2; index++, first2++) {
        tempArr[index] = arr[first2];
        moveCount++;
    }

    for (index = first; index <= last; ++index){
        arr[index] = tempArr[index - first];
        moveCount++;
    }

}

void printArray(int *arr, int n){
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;
}

// the implementation relies on the slides
void radixSort(int *arr, int n) {
    if (n > 0) {
        //cout << "inside radix function  " << n << endl;
        int d = calcD(arr, n);
        int exp = 1;
        for (int j = d; j > 0; j--) {
            int groups[10][n]; // initializing 10 groups
            int counter[10] = {0};   // initializing a counter for each group

            for (int i = 0; i < n; i++) {
                int k = (arr[i] / exp) % 10;
                groups[k][counter[k]] = arr[i];
                counter[k]++;
            }
            exp *= 10;

            int k = 0; // counter for arr
            for (int i = 0; i < 10; i++){
                for (int j = 0; j < counter[i]; j++)
                    arr[k++] = groups[i][j]; // replacing the items in the original array
            }
        } // j
    } // if

}

int calcD(int *arr, int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx)
            mx = arr[i];
    }

    int d = 0;
    for (int i = 1; mx / i > 0; i *= 10, d++);
    return d;
}

double calcDuration(int *arr, int n, int i, int *compCount, int *moveCount, int sortType) {
    double duration = 0;

    int M = 100;

    int *tempArr[M];
    for (int k = 0; k < M; k++)
        tempArr[k] = new int[n];

    for (int k = 0; k < M; k++) {
        for (int j = 0; j < n; j++)
            tempArr[k][j] = arr[j];
    }

    clock_t startTime = clock();
    for (int j = 0; j < M; j++) {
        if (sortType == 1)
            radixSort(tempArr[j], n);

        else if (sortType == 2 && j < 1) {
            bubbleSort(tempArr[j], n, compCount[i], moveCount[i]);
            break;
        }

        else if (sortType == 3)
            mergeSort(tempArr[j], n, compCount[i], moveCount[i]);

        else
            quickSort(tempArr[j], n, compCount[i], moveCount[i]);
    }


    duration = double(clock() - startTime ) / 1000.0;
    if (sortType != 2) duration /= M;

    for (int k = 0; k < M; k++)
        delete [] tempArr[k];

    return duration;
}

void printAnalysis(double elTime[4][8], int compCount[4][8], int moveCount[4][8]) {
    string dashes = "---------------------------------------------------------------------------------------\n";
    string header = "Part c - Time analysis of ";
    string header2Radix = "Array size\t\tTime Elapsed";
    string header2 = "Array size\t\tTime Elapsed\t\tcompCount\t\tmoveCount";


    cout << dashes << header << "Radix Sort\n" << header2Radix << endl;
    for (int i = 0; i < 8; i++) {
        printf("%*d", 10, 2000 + i * 4000);
	printf("%*g", 23, elTime[0][i]);
	cout << " ms" << endl;
    }

    cout << dashes << header << "Bubble Sort\n" << header2 << endl;
    for (int i = 0; i < 8; i++) {
        printf("%*d", 10, 2000 + i * 4000);
        printf("%*g", 23, elTime[1][i]);
	cout << " ms";
        printf("%*d", 21, compCount[1][i]);
        printf("%*d", 24, moveCount[1][i]);
        cout << endl;
    }

    cout << dashes << header << "Merge Sort\n" << header2 << endl;
    for (int i = 0; i < 8; i++) {
        printf("%*d", 10, 2000 + i * 4000);
        printf("%*g", 23, elTime[2][i]);
        cout << " ms";
        printf("%*d", 21, compCount[2][i]);
        printf("%*d", 24, moveCount[2][i]);
        cout << endl;
    }

    cout << dashes << header << "Quick Sort\n" << header2 << endl;
    for (int i = 0; i < 8; i++) {
        printf("%*d", 10, 2000 + i * 4000);
        printf("%*g", 23, elTime[3][i]);
        cout << " ms";
        printf("%*d", 21, compCount[3][i]);
        printf("%*d", 24, moveCount[3][i]);
        cout << endl;
    }
}

void performanceAnalysis() {
    double elTime[4][8];
    int compCount[4][8];
    int moveCount[4][8];

    double duration;

    for (int i = 0; i < 8; i++) {
        int n = 2000 + i * 4000;
        int arr1[n];
        int arr2[n];
        int arr3[n];
        int arr4[n];

        srand(time(NULL));
        for (int j = 0; j < n; j++)
            arr1[j] = arr2[j] = arr3[j] = arr4[j] = rand();


        duration = calcDuration(arr1, n, i, compCount[0], moveCount[0], 1);
        elTime[0][i] = duration;

        duration = calcDuration(arr2, n, i, compCount[1], moveCount[1], 2);
        elTime[1][i] = duration;

        duration = calcDuration(arr3, n, i, compCount[2], moveCount[2], 3);
        elTime[2][i] = duration;

        duration = calcDuration(arr4, n, i, compCount[3], moveCount[3], 4);
        elTime[3][i] = duration;
    }

    printAnalysis(elTime, compCount, moveCount);
}
