/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of HuffmanHeap
*/


#include <cstdio>
#include "HuffmanHeap.h"
#include <iostream>

using namespace std;

HuffmanHeap::HuffmanHeap() {
    n = 0;
}

bool HuffmanHeap::isEmpty() {
    return n == 0;
}

void HuffmanHeap::insert(HuffmanHeap::MinHeapNode *newItem) {
    if (n >= MAX_SIZE)
        cout << "Insertion failed: HuffmanHeap is full" << endl;

    items[n] = newItem;

    int place = n;
    int parent = (place - 1) / 2;
    while( (place > 0) && (items[place]->freq < items[parent]->freq)) {
        HuffmanHeap::MinHeapNode* temp = items[parent];
        items[parent] = items[place];
        items[place] = temp;

        // Assigning left and right children of the moved node
        //assignChildren(place);

        place = parent;
        parent = (place - 1) / 2;
    }
    n++;
    //assignChildren(place);
}

/*void HuffmanHeap::assignChildren(int place) {
    int child = place*2+1;
    if (child <= n)
        items[place]->left = items[child];
    else
        items[place]->left = NULL;

    // right child
    if (++child <= n)
        items[place]->right = items[child];
    else
        items[place]->right = NULL;
}*/

HuffmanHeap::MinHeapNode* HuffmanHeap::peek() {
    if (isEmpty())
        return NULL;

    return items[0];
}

HuffmanHeap::MinHeapNode* HuffmanHeap::extractMin() {
    if (isEmpty())
        return  NULL;

    HuffmanHeap::MinHeapNode* temp = items[0];
    items[0] = items[--n];
    rebuild(0);
    return temp;
}

void::HuffmanHeap::rebuild(int root) {
    int child = 2 * root + 1;
    if (child < n) {
        int rchild = child + 1;
        if ( (rchild < n) && (items[rchild]->freq < items[child]->freq) )
            child = rchild;

        if (items[root]->freq > items[child]->freq) {
            HuffmanHeap::MinHeapNode* temp = items[root];
            items[root] = items[child];
            items[child] = temp;

            rebuild(child);
        }
    }
    //assignChildren(root);
}