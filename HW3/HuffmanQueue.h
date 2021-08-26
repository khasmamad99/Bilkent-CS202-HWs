/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Header file for HuffmanQueue
*/


#ifndef HW3_HUFFMANQUEUE_H
#define HW3_HUFFMANQUEUE_H

#include "HuffmanHeap.h"

class HuffmanQueue {
public:
    bool isEmpty();
    void insert(HuffmanHeap::MinHeapNode* newItem);
    HuffmanHeap::MinHeapNode*  extractMin();

private:
    HuffmanHeap h;
};


#endif //HW3_HUFFMANQUEUE_H
