/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Header file for HuffmanHeap
*/


#include <cstdio>


#ifndef HW3_HUFFMANHEAP_H
#define HW3_HUFFMANHEAP_H

const int MAX_SIZE = 1023;

class HuffmanHeap {
public:
    struct MinHeapNode {
        char character;
        int freq;
        MinHeapNode *left = NULL;
        MinHeapNode *right = NULL;
    };

    HuffmanHeap();          // default constructor

    bool isEmpty();
    void insert(MinHeapNode* newItem);
    MinHeapNode* extractMin();
    MinHeapNode* peek();
    int size();

private:
    int n;
    MinHeapNode* items[MAX_SIZE];
    void assignChildren(int index);
    void rebuild(int root);
};


#endif //HW3_HUFFMANHEAP_H
