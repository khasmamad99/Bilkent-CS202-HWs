/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Implementation of HuffmanQueue
*/

#include "HuffmanQueue.h"

bool HuffmanQueue::isEmpty() {
    return h.isEmpty();
}

void HuffmanQueue::insert(HuffmanHeap::MinHeapNode *newItem) {
    h.insert(newItem);
}

HuffmanHeap::MinHeapNode* HuffmanQueue::extractMin() {
    return h.extractMin();
}
