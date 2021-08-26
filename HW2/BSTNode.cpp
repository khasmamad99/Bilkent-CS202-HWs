/**
* Title : Binary Search Tree Node Class Implementation
* Author : Khasmamad Shabanovi
* ID: 21701333
* Section : 2
* Assignment : 2
* Description : Implementation of BST
*/

#include <cstdio>
#include "BSTNode.h"

// Default Constructor
BSTNode::BSTNode() {
    item = 0;
    leftPtr = NULL;
    rightPtr = NULL;
}

// Constructors
BSTNode::BSTNode(const int& nodeItem) {
    item = nodeItem;
    leftPtr = NULL;
    rightPtr = NULL;
}

BSTNode::BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right) {
    item = nodeItem;
    leftPtr = left;
    rightPtr = right;
}

// Methods
int BSTNode::getItem() {
    return item;
}