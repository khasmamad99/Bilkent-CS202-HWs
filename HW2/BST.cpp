/**
* Title : Binary Search Tree Class Implementation
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 2
* Description : Implementation of BST class
*/

#include "BST.h"
#include <iostream>
using namespace std;


// Default Constructor
BST::BST(){
    rootPtr = NULL;
}

// Constructors
BST::BST(const int& rootItem){
    rootPtr = new BSTNode(rootItem, NULL, NULL);
}

BST::BST(const int& rootItem, const BST *leftPtr, const BST *rightPtr) {
    rootPtr = new BSTNode(rootItem, copyTree(leftPtr->rootPtr), copyTree(rightPtr->rootPtr));
}

// Copy constructor
BST::BST(const BST &tree) {
    rootPtr = copyTree(tree.rootPtr);
}

// copyTree
BSTNode* BST::copyTree(const BSTNode *treePtr) {
    BSTNode* newTreePtr = NULL;
    if (treePtr != NULL){
        newTreePtr = new BSTNode(treePtr->item, NULL, NULL);
        newTreePtr->rightPtr = copyTree(treePtr->rightPtr);
        newTreePtr->leftPtr = copyTree(treePtr->leftPtr);
    }

    return newTreePtr;
}

// Destructor
BST::~BST() {
    destroyTree(rootPtr);
}

// destroyTree
void BST::destroyTree(BSTNode *subTreePtr) {
    if (subTreePtr != NULL){
        destroyTree(subTreePtr->leftPtr);
        destroyTree(subTreePtr->rightPtr);
        delete subTreePtr;
    }
}

bool BST::isEmpty() const {
    return rootPtr == NULL;
}

// Function for inserting a new item
void BST::insertItem(int key) {
    insertItem(rootPtr, key);
}

// Helper function for inserting
void BST::insertItem(BSTNode *&treePtr, const int &key){
    if (treePtr == NULL){
        treePtr = new BSTNode(key);
        if (treePtr == NULL)
            cout << "Insertion failed" << endl;
    }
    else if (key < treePtr->item)
        insertItem(treePtr->leftPtr, key);
    else
        insertItem(treePtr->rightPtr, key);
}

// Function for deleting an item
void BST::deleteItem(int key) {
    deleteItem(rootPtr, key);
}

// Helper function for deleting
void BST::deleteItem(BSTNode *&treePtr, int key) {
    if (treePtr == NULL)
        cout << "Delete failed: no item with the given key is found" << endl;

    else if (key == treePtr->item)
        deleteNodeItem(treePtr);

    else if (key < treePtr->item)
        deleteItem(treePtr->leftPtr, key);
    else
        deleteItem(treePtr->rightPtr, key);
}

void BST::deleteNodeItem(BSTNode *&nodePtr) {
    BSTNode *delPtr;
    int repItem;

    // CASE 1: Leaf node
    if ((nodePtr->leftPtr == NULL) && (nodePtr->rightPtr == NULL)) {
        delete nodePtr;
        nodePtr = NULL;
    }

    // CASE 2: No left child
    else if (nodePtr->leftPtr == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = NULL;
        delete delPtr;
    }

    // CASE 2: No right child
    else if (nodePtr->rightPtr == NULL){
        delPtr = nodePtr;
        nodePtr = nodePtr->leftPtr;
        delPtr->leftPtr = NULL;
        delete delPtr;
    }

    // CASE 3: Two children
    else {
        processLeftmost(nodePtr->rightPtr, repItem);
        nodePtr->item = repItem;
    }
}

void BST::processLeftmost(BSTNode *&nodePtr, int &treeItem) {
    if (nodePtr->leftPtr == NULL){
        treeItem = nodePtr->item;
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightPtr;
        delPtr->rightPtr = NULL;
        delete delPtr;
    } else
        processLeftmost(nodePtr->leftPtr, treeItem);
}

// Function for item retrieval
BSTNode* BST::retrieveItem(int key) {
    return retrieveItem(rootPtr, key);
}

// Helper function for retrieve
BSTNode* BST::retrieveItem(BSTNode *treePtr, int key) {
    if (treePtr == NULL) {
        cout << "Search key not found, returning null" << endl;
        return NULL;
    }

    else if (key == treePtr->item)
        return treePtr;

    else if (key < treePtr->item)
        return retrieveItem(treePtr->leftPtr, key);

    else
        return retrieveItem(treePtr->rightPtr, key);
}

// Inorder traversal
int* BST::inorderTraversal(int &length) {
    length = 0;
    int *arr = NULL;
    findLength(rootPtr, length);
    if (length != 0) {
        arr = new int[length];
        int i = 0;
        inorderTraversal(rootPtr, arr, i);
    }
    return arr;
}

void BST::findLength(BSTNode *treePtr, int &length) {
    if (treePtr != NULL) {
        length++;
        findLength(treePtr->leftPtr, length);
        findLength(treePtr->rightPtr, length);
    }
}

void BST::inorderTraversal(BSTNode *treePtr, int *arr, int &i) {
    if (treePtr != NULL) {
        inorderTraversal(treePtr->leftPtr, arr, i);
        arr[i++] = treePtr->item;
        inorderTraversal(treePtr->rightPtr, arr, i);
    }
}

// Contains sequence
bool BST::containsSequence(int *seq, int length) {
    if (length == 0)
        return true;

    int low = seq[0];
    int high = seq[length - 1];
    bool contains = true;
    int i = 0;
    containsSequence(rootPtr, seq, length, i, low, high, contains);
    return contains && i == length;
}

void BST::containsSequence(BSTNode *treePtr, int *seq, int length, int &i, int low, int high, bool &contains) {
    if (contains && treePtr != NULL){
        if (treePtr->item > low)
            containsSequence(treePtr->leftPtr, seq, length, i, low, high, contains);

        cout << "Visiting node: " << treePtr->item << endl;

        if (treePtr->item >= low && treePtr->item <= high)
            contains = (treePtr->item == seq[i++]);

        if (treePtr->item < high)
            containsSequence(treePtr->rightPtr, seq, length, i, low, high, contains);
    }
}

// Counting nodes deeper than
int BST::countNodesDeeperThan(int level) {
    int currentLevel = 1;
    int count = 0;
    countNodesDeeperThan(rootPtr, level, currentLevel, count);
    return count;
}

void BST::countNodesDeeperThan(BSTNode *treePtr, int level, int &currentLevel, int &count) {
    if (treePtr != NULL){
        currentLevel++;
        countNodesDeeperThan(treePtr->leftPtr, level, currentLevel, count);
        currentLevel--;

        if (currentLevel >= level)
            count++;

        currentLevel++;
        countNodesDeeperThan(treePtr->rightPtr, level, currentLevel, count);
        currentLevel--;
    }
}

// max balanced height
int BST::maxBalancedHeight() {
    return maxBalancedHeight(rootPtr);
}

int BST::maxBalancedHeight(BSTNode *treePtr) {
    if (treePtr == NULL)
        return 0;

    else {
        int leftHeight = maxBalancedHeight(treePtr->leftPtr);
        int rightHeight = maxBalancedHeight(treePtr->rightPtr);

        if (leftHeight == rightHeight)
            return 1 + leftHeight;
        else
            return 2 + min(leftHeight, rightHeight);
    }
}