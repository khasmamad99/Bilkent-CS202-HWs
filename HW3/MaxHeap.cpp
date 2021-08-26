/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of MaxHeap
*/


#include "MaxHeap.h"
#include <iostream>
using namespace std;

// Constructor
MaxHeap::MaxHeap() {
    n = 0;
}

bool MaxHeap::isEmpty() const {
    return n == 0;
}

void MaxHeap::insert(int value) {
    if (n >= MAX_HEAP)
        cout << "Insertion failed: Heap is full" << endl;

    items[n] = value;

    int place = n;
    int parent = (place - 1) / 2;
    while( (place > 0 ) && (items[place] > items[parent])) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    n++;
}

int MaxHeap::peek() {
    if (isEmpty())
        return -1;

    return items[0];
}

int MaxHeap::extractMax() {
    if (isEmpty())
        return -1;

    int max = items[0];
    items[0] = items[--n];
    rebuild(0);
    return max;
}

int MaxHeap::size() {
    return n;
}

void MaxHeap::rebuild(int root) {
    int child = 2 * root + 1;
    if (child < n) {
        int rchild = child + 1;
        if ( (rchild < n) && (items[rchild] > items[child]) )
            child = rchild;

        if (items[root] < items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            rebuild(child);
        }
    }
}