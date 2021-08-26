/**
* Title : Main function
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 2
* Description : Main function
*/
#include <iostream>
#include "BST.h"
using namespace std;

void printArr(int *arr, int length){
    for (int i = 0; i < length; i++)
        cout << arr[i] << " ";
    cout << "Length: " << length << endl;
}

int main() {
    BST bst = BST(8);
    bst.insertItem(4);
    bst.insertItem(3);
    bst.insertItem(1);
    bst.insertItem(2);
    bst.insertItem(6);
    bst.insertItem(5);
    bst.insertItem(13);
    bst.insertItem(12);
    bst.insertItem(10);
    bst.insertItem(15);
    bst.insertItem(14);

    int *arr;
    int length;
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Deleting a leaf node: 10" << endl;
    bst.deleteItem(10);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Inserting 10: " << endl;
    bst.insertItem(10);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Deleting a node with one child: 6" << endl;
    bst.deleteItem(6);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Inserting 6: " << endl;
    bst.insertItem(6);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Deleting a node with two children: 13" << endl;
    bst.deleteItem(13);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Inserting 13: " << endl;
    bst.insertItem(13);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Deleting a non-existent node: 16" << endl;
    bst.deleteItem(16);
    arr = bst.inorderTraversal(length);
    printArr(arr, length);

    cout << "Retrieving item: 3" <<  endl;
    BSTNode *node = bst.retrieveItem(3);
    cout << node->getItem() << endl;

    cout << "Retrieving a non-existent item: 16" << endl;
    node = bst.retrieveItem(16);
    if (node != NULL)
        cout << node->getItem() << endl;

    cout << "Testing containsSequence..." << endl;
    cout << "containsSequence([1, 2, 3, 4, 5, 6], 6)" << endl;
    int testArr[6] = {1,2,3,4,5,6};
    bool contains = bst.containsSequence(testArr, 6);
    if (contains)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "containsSequence([10, 12, 13, 15], 4)" << endl;
    int testArr2[4] = {10,12,13,15};
    contains = bst.containsSequence(testArr2, 4);
    if (contains)
        cout << "True" << endl;
    else
        cout << "False" << endl;

    cout << "containsSequence([10, 12, 13, 14, 15, 16], 6)" << endl;
    int testArr3[6] = {10,12,13,14,15,16};
    contains = bst.containsSequence(testArr3, 6);
    if (contains)
        cout << "True" << endl;
    else
        cout << "False\n" << endl;


    cout << "Testing countNodesDeeperThan: level = 4" << endl;
    cout << bst.countNodesDeeperThan(4) << endl << endl;

    cout << "Testing maxBalancedheight:" << endl;
    cout << bst.maxBalancedHeight() << endl << endl;

    return 0;
}