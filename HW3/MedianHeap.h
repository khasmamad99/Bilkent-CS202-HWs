/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Header file for MedianHeap
*/


#ifndef HW3_MEDIANHEAP_H
#define HW3_MEDIANHEAP_H

#include "MinHeap.h"
#include "MaxHeap.h"

class MedianHeap {
public:
    MedianHeap();       // default constructor

    void insert(int value);
    int findMedian();
    bool isEmpty();

private:
    MaxHeap maxh;
    MinHeap minh;

};


#endif //HW3_MEDIANHEAP_H
