/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of MinHeap
*/


#include "MinHeap.h"
#include <iostream>
using namespace std;

// Constructor
MinHeap::MinHeap() {
    n = 0;
}

bool MinHeap::isEmpty() const {
    return n == 0;
}

void MinHeap::insert(int value) {
    if (n >= MIN_HEAP)
        cout << "Insertion failed: Heap is full" << endl;

    items[n] = value;

    int place = n;
    int parent = (place - 1) / 2;
    while( (place > 0 ) && (items[place] < items[parent])) {
        int temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        place = parent;
        parent = (place - 1) / 2;
    }
    n++;
}

int MinHeap::peek() {
    if (isEmpty())
        return -1;

    return items[0];
}

int MinHeap::extractMin() {
    if (isEmpty())
        return -1;

    int min = items[0];
    items[0] = items[--n];
    rebuild(0);
    return min;
}

int MinHeap::size() {
    return n;
}

void MinHeap::rebuild(int root) {
    int child = 2 * root + 1;
    if (child < n) {
        int rchild = child + 1;
        if ( (rchild < n) && (items[rchild] < items[child]) )
            child = rchild;

        if (items[root] > items[child]) {
            int temp = items[root];
            items[root] = items[child];
            items[child] = temp;
            rebuild(child);
        }
    }
}
