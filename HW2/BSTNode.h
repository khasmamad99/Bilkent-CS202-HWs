/**
* Title : Binary Search Tree Node header file
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 2
* Description : Header file for BSTNode class
*/


#ifndef CODE_BSTNODE_H
#define CODE_BSTNODE_H


class BSTNode {
public:
    // Constuctors & Destructor
    BSTNode();
    BSTNode(const int& nodeItem);
    BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right);

    // Public methods
    int getItem();
private:
    // Data members
    int item;
    BSTNode *leftPtr;
    BSTNode *rightPtr;

    // Friend class
    friend class BST;
};


#endif //CODE_BSTNODE_H
