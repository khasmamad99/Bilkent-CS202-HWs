/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Header file for MaxHeap
*/


#ifndef HW3_MAXHEAP_H
#define HW3_MAXHEAP_H

const int MAX_HEAP = 1023;

class MaxHeap {
public:
    MaxHeap();         // default constructor

    bool isEmpty() const;
    void insert(int value);
    int peek();
    int extractMax();
    int size();

protected:
    void rebuild(int root);

private:
    int items[MAX_HEAP];
    int n;
};


#endif //HW3_MAXHEAP_H
