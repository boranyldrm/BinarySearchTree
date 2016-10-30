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

// finding number of nodes
int BinarySearchTree::getNumberOfNodes() {
    countNodes(root, numNodes);
    return numNodes;
}

int BinarySearchTree::countNodes(BinaryNode *node, int &num) {
    if (node == NULL)
        return 0;
    numNodes = 1 + countNodes(node->left, numNodes) + countNodes(node->right, numNodes);
    return numNodes;
}

// end finding number of nodes

BinaryNode* BinarySearchTree::insert(BinaryNode *&node, const int &newEntry) {
    if (node == NULL)
        node = new BinaryNode(newEntry);

    else if(node->data > newEntry)
        node->left = insert(node->left, newEntry);
    else if(node->data < newEntry)
        node->right = insert(node->right, newEntry);

    return node;
}

bool BinarySearchTree::add(const int &newEntry) {

    BinaryNode *flag = insert(root, newEntry);
    return (bool) flag;
    /*
    if (isEmpty()) {
        root = new BinaryNode(newEntry);
        return true;
    }
    else
        return root->add(newEntry);*/
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

void BinarySearchTree::preorder(BinaryNode *node) {
    if (node != NULL) {
        cout << node->data << endl;
        preorder(node->left);
        preorder(node->right);
    }
}

void BinarySearchTree::inorderTraverse() {
    inorder(root);
}

void BinarySearchTree::inorder(BinaryNode *node) {
    if (node != NULL) {
        inorder(node->left);
        cout << node->data << endl;
        inorder(node->right);
    }
}

void BinarySearchTree::postorderTraverse() {
    postorder(root);
}

void BinarySearchTree::postorder(BinaryNode *node) {
    if (node != NULL) {
        postorder(node->left);
        postorder(node->right);
        cout << node->data << endl;
    }
}


void BinarySearchTree::levelorderTraverse() {

}

int BinarySearchTree::span(const int &a, const int &b) {
    return 0;
}

void BinarySearchTree::mirror() {

}

void BinarySearchTree::trim(const int &min, const int &max) {
    trim(root, min, max);
}

void BinarySearchTree::trim(BinaryNode *node, const int &min, const int &max) {
    if (node != NULL) {
        //cout << node->data << "debug data" << endl;
        if (node->data < min) {
            BinaryNode *tmp = node;
            node = node->right;
            destroyTree(tmp);
        }
        else if (node->data > max) {
            BinaryNode *tmp = node;
            node = node->left;
            destroyTree(tmp);
        }
        else {
            trim(node->left, min, max);
            trim(node->right, min, max);
        }
    }
}


bool BinarySearchTree::checkBST(BinaryNode* node) {
    if(node->left == NULL || node->right == NULL) {
        return true;
    }
    else if(node->left != NULL && node->left->data < node->data) {
        return checkBST(node->left);
    }
    else if(node->right != NULL && node->right->data > node->data) {
        return checkBST(node->right);
    }
    return false;
}

bool BinarySearchTree::checkBST() {
    return checkBST(root);
}

bool BinarySearchTree::isbalancedTree() {
    return isbalancedTree(root);
}

bool BinarySearchTree::isbalancedTree(BinaryNode *node) {
    // {(if node = null return true)} OR
    // {(left AND right is balanced AND
    // absolute value of left height - right height <= 1
    // return true)}
    return (node == NULL) ||
    (isbalancedTree(node->left) &&
     isbalancedTree(node->right) &&
     abs(findHeight(node->left) - findHeight(node->right)) <= 1);
}

bool BinarySearchTree::isfullTree() {
    return isfullTree(root);
}

bool BinarySearchTree::isfullTree(BinaryNode *node) {
    if (node == NULL)
        return true;
    if((node->left != NULL && node->right == NULL) ||
            (node->left == NULL && node->right != NULL))
        return false;
    else
        return isfullTree(node->left) && isfullTree(node->right);
}


bool BinarySearchTree::iscompleteTree() {
    return false;
}

bool BinarySearchTree::iscompleteTree(BinaryNode *node) {
    return false;
}

int BinarySearchTree::inorderSuccessor(const int &value) {
    return inorderSuccessor(root, value);
}

int BinarySearchTree::inorderSuccessor(BinaryNode *node, const int &value) {
    if (value < node->data)
        return inorderSuccessor(node->left, value);
    else if (value > node->data)
        return inorderSuccessor(node->right, value);
    else if (value == node->data) {
        if (node->right->left == NULL)
            return node->right->data;
        else
            return goLeft(node->right->left);
    }
    return -1;
}

int BinarySearchTree::goLeft(BinaryNode *node) {
    if(node->left == NULL)
        return node->data;
    else
        return goLeft(node->left);
}
