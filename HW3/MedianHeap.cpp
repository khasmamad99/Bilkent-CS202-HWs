/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of MedianHeap
*/


#include "MedianHeap.h"

MedianHeap::MedianHeap() {
    maxh = MaxHeap();
    minh = MinHeap();
}

bool MedianHeap::isEmpty() {
    return (maxh.isEmpty() && minh.isEmpty());
}

void MedianHeap::insert(int value) {
    if (isEmpty())
        minh.insert(value);

    else {
        if (value >= findMedian())
            minh.insert(value);
        else
            maxh.insert(value);

        if (minh.size() - maxh.size() > 1 )
            maxh.insert(minh.extractMin());
        if (maxh.size() - minh.size() > 1)
            minh.insert(maxh.extractMax());
    }
}

int MedianHeap::findMedian() {
    if (maxh.size() > minh.size())
        return maxh.peek();
    else
        return minh.peek();
}
