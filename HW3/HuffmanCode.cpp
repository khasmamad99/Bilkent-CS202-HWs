/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of HuffmanCode
*/


#include <cstdio>
#include "HuffmanCode.h"

HuffmanHeap::MinHeapNode* huffman(HuffmanHeap::MinHeapNode* *C, int n) {
    if (n <= 0)
        return NULL;

    HuffmanQueue Q = HuffmanQueue();
    for (int i = 0; i < n; i++) {
        Q.insert(C[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        HuffmanHeap::MinHeapNode* temp = new HuffmanHeap::MinHeapNode;
        temp->left = Q.extractMin();
        temp->right = Q.extractMin();
        temp->freq = temp->left->freq + temp->right->freq;
        Q.insert(temp);
    }
    return Q.extractMin();
}

