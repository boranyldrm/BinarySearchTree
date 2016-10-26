//
// Created by Boran Yildirim on 26.10.2016.
//

#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

// constructors

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    height = 0;
    numNodes = 0;
}

BinarySearchTree::BinarySearchTree(const int &entry) {
    root = new BinaryNode(entry);
    height = 1;
    numNodes = 1;
}


BinarySearchTree::BinarySearchTree(BinarySearchTree &tree) {
    copyTree(tree.root, root);
    height = tree.height;
    numNodes = tree.numNodes;
}

void BinarySearchTree::copyTree(BinaryNode *treePtr, BinaryNode *&newTreePtr) const {
    if (treePtr != NULL) {
        newTreePtr = new BinaryNode(treePtr->data);
        copyTree(treePtr->left, newTreePtr->left);
        copyTree(treePtr->right, newTreePtr->right);
    }
    else
        newTreePtr = NULL;
}

// end constructors

// destructor

BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

void BinarySearchTree::destroyTree(BinaryNode *&treePtr) {
    if (treePtr != NULL) {
        destroyTree(treePtr->left);
        destroyTree(treePtr->right);
        delete treePtr;
        treePtr = NULL;
    }
}

// end destructor

bool BinarySearchTree::isEmpty() {
    return root == NULL;
}

// finding height

int BinarySearchTree::getHeight() {
    if (isEmpty())
        return 0;
    else
        return findHeight(root);
}

int BinarySearchTree::findHeight (BinaryNode *node) {
    if (node == NULL)
        return 0;
    return 1 + max(findHeight(node->left), findHeight(node->right));
}

// end finding height

int BinarySearchTree::getNumberOfNodes() {
    return 0;
}

bool BinarySearchTree::add(const int &newEntry) {
    if (isEmpty()) {
        root = new BinaryNode(newEntry);
        return true;
    }
    else
        return root->add(newEntry);
}

// removing

bool BinarySearchTree::remove(const int &entry) {
    return deleteNode(root, entry);
}

bool BinarySearchTree::deleteNode(BinaryNode *node, const int &entry) {
    if (node == NULL)
        return false;
    else if (entry == node->data)
        return deleteNodeItem(node);
    else if (entry > node->data)
        return deleteNode(node->right, entry);
    else if (entry < node->data)
        return deleteNode(node->left, entry);
    return false;
}

bool BinarySearchTree::deleteNodeItem(BinaryNode * &nodePtr) {
    BinaryNode *delPtr;
    int replacementItem;

    // (1)  Test for a leaf
    if ((nodePtr->left == NULL) && (nodePtr->right == NULL)) {
        delete nodePtr;
        nodePtr = NULL;
    }

    //(2)  Test for no left child
    else if (nodePtr->left == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = NULL;
        delete delPtr;
    }

    // (3)  Test for no right child
    else if (nodePtr->right == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->left;
        delPtr->left = NULL;
        delete delPtr;
    }

    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else {
        processLeftmost(nodePtr->right, replacementItem);
        nodePtr->data = replacementItem;
    }

    return true;
}


void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int &treeItem){
    if (nodePtr->left == NULL) {
        treeItem = nodePtr->data;
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->right;
        delPtr->right = NULL; // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->left, treeItem);
}

// end removing

bool BinarySearchTree::contains(const int &entry) {
    return false;
}

void BinarySearchTree::preorderTraverse() {
    preorder(root);
}

void BinarySearchTree::preorder(BinaryNode *root) {
    if (root != NULL) {
        cout << root->data << endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void BinarySearchTree::inorderTraverse() {
    inorder(root);
}

void BinarySearchTree::inorder(BinaryNode *root) {
    if (root != NULL) {
        preorder(root->left);
        cout << root->data << endl;
        preorder(root->right);
    }
}

void BinarySearchTree::postorderTraverse() {
    postorder(root);
}

void BinarySearchTree::postorder(BinaryNode *root) {
    if (root != NULL) {
        preorder(root->left);
        preorder(root->right);
        cout << root->data << endl;
    }
}


void BinarySearchTree::levelorderTraverse() {

}

int BinarySearchTree::span(const int &a, const int &b) {
    return 0;
}

void BinarySearchTree::mirror() {

}
