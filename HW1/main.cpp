/**
* Title : Algorithm Efficiency and Sorting
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 1
* Description : Main program
*/
#include <iostream>
#include "sorting.h"
using namespace std;

int main() {
    int compCount;
    int moveCount;

    // bubbleSort
    int arr1[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    cout << "Performing bubbleSort: ";
    bubbleSort(arr1, 16, compCount, moveCount);
    printArray(arr1, 16);
    cout << "compCount: " << compCount << " moveCount: " << moveCount << endl;

    // quickSort
    int arr2[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    cout << "Performing quickSort: ";
    quickSort(arr2, 16, compCount, moveCount);
    printArray(arr2, 16);
    cout << "compCount: " << compCount << " moveCount: " << moveCount << endl;

    // mergeSort
    int arr3[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    cout << "Performing mergeSort: ";
    mergeSort(arr3, 16, compCount, moveCount);
    printArray(arr3, 16);
    cout << "compCount: " << compCount << " moveCount: " << moveCount << endl;

    // radixSort
    cout << "Performing radixSort: ";
    int arr4[] = {7,3,6,12,13,4,1,9,15,0,11,14,2,8,10,5};
    radixSort(arr4, 16);
    printArray(arr4, 16);

    performanceAnalysis();

    return 0;
}
