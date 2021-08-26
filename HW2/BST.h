/**
* Title : Binary Search Tree header file
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 2
* Description : Header file for BST class
*/

#ifndef CODE_BST_H
#define CODE_BST_H

#include "BSTNode.h"

class BST {
public:
    // Constructors
    BST();
    BST(const int& rootItem);
    BST(const int& rootItem, const BST *leftPtr, const BST *rightPtr);
    BST(const BST& treePtr);

    // Destructor
    ~BST();

    // Public methods
    bool isEmpty() const;
    void insertItem(int key);
    void deleteItem(int key);
    BSTNode *retrieveItem(int key);
    int *inorderTraversal(int &length);
    bool containsSequence(int *seq, int length);
    int countNodesDeeperThan(int level);
    int maxBalancedHeight();

protected:
    BSTNode *copyTree(const BSTNode *treePtr);
    void destroyTree(BSTNode *subTreePtr);

private:
    // Private methods
    void insertItem(BSTNode *&treePtr, const int& key);
    void deleteItem(BSTNode *&treePtr, int key);
    void deleteNodeItem(BSTNode *&nodePtr);
    void processLeftmost(BSTNode *&nodePtr, int &treeItem);
    BSTNode *retrieveItem(BSTNode *treePtr, int key);
    void findLength(BSTNode *treePtr, int &length);
    void inorderTraversal(BSTNode *treePtr, int *arr, int &i);
    void containsSequence(BSTNode *treePtr, int *seq, int length, int &i, int low, int high, bool &contains);
    void countNodesDeeperThan(BSTNode *treePtr, int level, int &currentLevel, int &count);
    int maxBalancedHeight(BSTNode *treePtr);

    // Data members
    BSTNode *rootPtr;
};


#endif //CODE_BST_H
