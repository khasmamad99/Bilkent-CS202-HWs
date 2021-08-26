/**
* Title : Heaps and AVL Trees
* Author : Khasmamad Shabanovi
* ID: 21 701333
* Section : 2
* Assignment : 3
* Description : Header file for MinHeap
*/


#ifndef HW3_MINHEAP_H
#define HW3_MINHEAP_H

const int MIN_HEAP = 1023;
class MinHeap {
public:
    MinHeap();         // default constructor

    bool isEmpty() const;
    void insert(int value);
    int peek();
    int extractMin();
    int size();

protected:
    void rebuild(int root);

private:
    int items[MIN_HEAP];
    int n;
};


#endif //HW3_MINHEAP_H
