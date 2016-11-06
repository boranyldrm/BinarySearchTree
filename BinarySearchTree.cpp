//
// Created by Boran Yildirim on 26.10.2016.
//

#include "BinarySearchTree.h"


// constructors

BinarySearchTree::BinarySearchTree() {
    root = NULL;
    height = 0;
    numNodes = 0;
}

BinarySearchTree::BinarySearchTree(const int &entry) {
    root = new BinaryNode(entry);
    height++;
    numNodes++;
}


BinarySearchTree::BinarySearchTree(BinarySearchTree &tree) {
    copyTree(tree.root, root);
    height = tree.getHeight();
    numNodes = tree.getNumberOfNodes();
}

void BinarySearchTree::copyTree(BinaryNode *treePtr, BinaryNode *&newTreePtr) const {
    if (treePtr != NULL) {
        newTreePtr = new BinaryNode(treePtr->getData());
        copyTree(treePtr->getLeft(), newTreePtr->getLeft());
        copyTree(treePtr->getRight(), newTreePtr->getRight());
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
        destroyTree(treePtr->getLeft());
        destroyTree(treePtr->getRight());
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
    return 1 + max(findHeight(node->getLeft()), findHeight(node->getRight()));
}

// end finding height

// finding number of nodes
int BinarySearchTree::getNumberOfNodes() {
    countNodes(root);
    return numNodes;
}

int BinarySearchTree::countNodes(BinaryNode *node) {
    if (node == NULL)
        return 0;
    numNodes = 1 + countNodes(node->getLeft()) + countNodes(node->getRight());
    return numNodes;
}

// end finding number of nodes

BinaryNode* BinarySearchTree::insert(BinaryNode *&node, const int &newEntry) {
    if (node == NULL)
        node = new BinaryNode(newEntry);

    else if(node->getData() > newEntry)
        node->setLeft(insert(node->getLeft(), newEntry));
    else if(node->getData() < newEntry)
        node->setRight(insert(node->getRight(), newEntry));

    return node;
}

bool BinarySearchTree::add(const int &newEntry) {
    BinaryNode *flag = insert(root, newEntry);
    return (bool) flag;
}

// removing

bool BinarySearchTree::remove(const int &entry) {
    return deleteNode(root, entry);
}

bool BinarySearchTree::deleteNode(BinaryNode *&node, const int &entry) {
    if (node != NULL) {
        if (entry == node->getData())
            return deleteNodeItem(node);
        else if (entry < node->getData())
            return deleteNode(node->getLeft(), entry);
        else if (entry > node->getData())
            return deleteNode(node->getRight(), entry);
    }
    return false;
}

bool BinarySearchTree::deleteNodeItem(BinaryNode *&nodePtr) {
    BinaryNode *delPtr;

    // (1)  Test for a leaf
    if ((nodePtr->getLeft() == NULL) && (nodePtr->getRight() == NULL)) {
        nodePtr = NULL;
        delete nodePtr;
    }

    //(2)  Test for no left child
    else if (nodePtr->getLeft() == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->getRight();
        delPtr->setRight(NULL);
        delete delPtr;
    }

    // (3)  Test for no right child
    else if (nodePtr->getRight() == NULL) {
        delPtr = nodePtr;
        nodePtr = nodePtr->getLeft();
        delPtr->setLeft(NULL);
        delete delPtr;
    }

    // (4)  There are two children:
    //      Retrieve and delete the inorder successor
    else {
        int replacementItem;
        processLeftmost(nodePtr->getRight(), replacementItem);
        nodePtr->setData(replacementItem);
    }

    return true;
}


void BinarySearchTree::processLeftmost(BinaryNode *&nodePtr, int &treeItem){
    if (nodePtr->getLeft() == NULL) {
        treeItem = nodePtr->getData();
        BinaryNode *delPtr = nodePtr;
        nodePtr = nodePtr->getRight();
        delPtr->setRight(NULL); // defense
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->getLeft(), treeItem);
}

// end removing

bool BinarySearchTree::contains(const int &entry) {
    if (root == NULL)
        return false;
    else
        return isContain(root, entry);
}


bool BinarySearchTree::isContain(BinaryNode *node, const int &entry) {
    if (node != NULL) {
        if (node->getData() == entry)
            return true;
        else if (entry < node->getData())
            return isContain(node->getLeft(), entry);
        else if (entry > node->getData())
            return isContain(node->getRight(), entry);
    }
    return false;
}

void BinarySearchTree::preorderTraverse() {
    preorder(root);
}

void BinarySearchTree::preorder(BinaryNode *node) {
    if (node != NULL) {
        cout << node->getData() << endl;
        preorder(node->getLeft());
        preorder(node->getRight());
    }
}

void BinarySearchTree::inorderTraverse() {
    inorder(root);
}

void BinarySearchTree::inorder(BinaryNode *node) {
    if (node != NULL) {
        inorder(node->getLeft());
        cout << node->getData() << endl;
        inorder(node->getRight());
    }
}

void BinarySearchTree::postorderTraverse() {
    postorder(root);
}

void BinarySearchTree::postorder(BinaryNode *node) {
    if (node != NULL) {
        postorder(node->getLeft());
        postorder(node->getRight());
        cout << node->getData() << endl;
    }
}


void BinarySearchTree::levelorderTraverse() {
    int height = findHeight(root);
    for (int i = 0; i <= height; ++i) {
        levelorder(root, i);
    }
}

void BinarySearchTree::levelorder(BinaryNode *node, const int &level) {
    if (node != NULL) {
        if (level == 1)
            cout << node->getData() << endl;
        else {
            levelorder(node->getLeft(), level - 1);
            levelorder(node->getRight(), level - 1);
        }
    }
}

int BinarySearchTree::span(const int &a, const int &b) {
    int result = 0;
    span(root, a, b, result);
    return result;
}

void BinarySearchTree::span(BinaryNode *node, const int &a, const int &b, int &result) {
    if (node != NULL) {
        if (node->getData() > a)
            span(node->getLeft(), a, b, result);
        if (node->getData() >= a && node->getData() <= b)
            result++;
        if (node->getData() < b)
            span(node->getRight(), a, b, result);
    }

}

void BinarySearchTree::mirror() {
    mirror(root);
}

void BinarySearchTree::mirror(BinaryNode *node) {
    if (node != NULL) {
        mirror(node->getLeft());
        mirror(node->getRight());
        swapSubtrees(node);
    }
}

void BinarySearchTree::swapSubtrees(BinaryNode *node) {
    if (node != NULL) {
        BinaryNode *tmp = node->getRight();
        node->setRight(node->getLeft());
        node->setLeft(tmp);
    }
}

void BinarySearchTree::trim(const int &min, const int &max) {
    trim(root, min, max);
}

void BinarySearchTree::trim(BinaryNode *node, const int &min, const int &max) {
    if (node != NULL) {
        //cout << node->data << "debug data" << endl;
        if (node->getData() < min) {
            BinaryNode *tmp = node;
            node = node->getRight();
            destroyTree(tmp);
        }
        else if (node->getData() > max) {
            BinaryNode *tmp = node;
            node = node->getLeft();
            destroyTree(tmp);
        }
        else {
            trim(node->getLeft(), min, max);
            trim(node->getLeft(), min, max);
        }
    }
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
    (isbalancedTree(node->getLeft()) &&
     isbalancedTree(node->getRight()) &&
     abs(findHeight(node->getLeft()) - findHeight(node->getRight())) <= 1);
}

bool BinarySearchTree::isfullTree() {
    return isfullTree(root);
}

bool BinarySearchTree::isfullTree(BinaryNode *node) {
    if (node == NULL)
        return true;
    if((node->getLeft() != NULL && node->getRight() == NULL) ||
            (node->getLeft() == NULL && node->getRight() != NULL))
        return false;
    else
        return isfullTree(node->getLeft()) && isfullTree(node->getRight());
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
    if (value < node->getData())
        return inorderSuccessor(node->getLeft(), value);
    else if (value > node->getData())
        return inorderSuccessor(node->getRight(), value);
    else if (value == node->getData()) {
        if (node->getRight()->getLeft() == NULL)
            return node->getRight()->getData();
        else
            return goLeft(node->getRight()->getLeft());
    }
    return -1;
}

int BinarySearchTree::goLeft(BinaryNode *node) {
    if(node->getLeft() == NULL)
        return node->getData();
    else
        return goLeft(node->getLeft());
}

