/**
* Title : Algorithm Efficiency and Sorting
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 1
* Description : header file for bubbleSort, quickSort, mergeSort,
                radixSort, and performanceAnalysis functions
*/

#ifndef SORTING_H
#define SORTING_H

void bubbleSort(int *arr, int n, int &compCount, int &moveCount);
void quickSort(int *arr, int n, int &compCount, int &moveCount);
void mergeSort(int *arr, int n, int &compCount, int &moveCount);
void radixSort(int *arr, int n);

int calcD(int *arr, int n);

void quickSort(int *arr, int first, int last, int &compCount, int &moveCount);
void partitionn(int *arr, int first, int last, int &pivotIndex, int &compCount, int &moveCount);
void swapp(int &first, int &second);

void mergeSort(int *arr, int first, int last, int &compCount, int &moveCount);
void mergee(int *arr, int first, int mid, int last, int &compCount, int &moveCount);

void printArray(int *arr, int n);
void performanceAnalysis();
void printAnalysis(double elTime[4][8], int compCount[4][8], int moveCount[4][8]);

double calcDuration(int *arr, int n, int i, int *&compCount, int *&moveCount, int sortType);


#endif // SORTING_H
