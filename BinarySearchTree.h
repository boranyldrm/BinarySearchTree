//
// Created by Boran Yildirim on 26.10.2016.
//

#ifndef ASSİGNMENT_2_BINARYSEARCHTREE_H
#define ASSİGNMENT_2_BINARYSEARCHTREE_H


#include "BinaryNode.h"

class BinarySearchTree {

public:

    // constructors
    BinarySearchTree ();
    BinarySearchTree (const int &entry);

    // copy constructor
    BinarySearchTree (BinarySearchTree &tree);

    // destructor
    ~BinarySearchTree ();

    // Tests whether the BST is empty. True if BST is empty; otherwise false.
    bool isEmpty ();

    // Gets the height of the BST.
    int getHeight ();

    // Gets the number of nodes in the BST.
    int getNumberOfNodes ();

    // Adds a new node containing a given data item to the BST.
    // If the data item already exists in the current BST, then don’t insert.
    // True if the addition is successful, or false if not.
    bool add (const int& newEntry);

    // Removes the node containing the given data item from BST.
    // True if the removal is successful, or false if not.
    bool remove (const int& entry);

    // Tests whether the given data item occurs in the BST.
    // True if the BST contains the given data item, or false if not.
    bool contains (const int& entry);

    // Traverses the BST in preorder and prints data item values in traversal order.
    void preorderTraverse ();

    // Traverses the BST in inorder and prints data item values in traversal order.
    void inorderTraverse ();

    // Traverses the BST in postorder and prints data item values in traversal order.
    void postorderTraverse ();

    // Traverses the BST in level-order and prints data item values in traversal order.
    // A level-order traversal of a tree processes (visits) nodes one level at a time,
    // from left to right, beginning with the root.
    void levelorderTraverse ();

    // Returns the number of nodes in the BST with data values within a specific range.
    // In other words, it is the number of nodes with the data value >=a and <=b.
    int span (const int& a, const int& b);

    // Changes the BST so that the roles of the left and right pointers are swapped at every node.
    // When you apply this function to a BST,
    // data value in a node will be less than the data values in its left subtree
    // and greater than the data values in its right subtree.
    // If you apply this function to the mirrored tree, you should obtain the original BST.
    void mirror ();


    //todo deneme
    void trim(const int &min, const int &max);
    void trim(BinaryNode *node, const int &min, const int &max);

    bool isbalancedTree();
    bool isbalancedTree(BinaryNode *node);

    bool isfullTree();
    bool isfullTree(BinaryNode *node);

    bool iscompleteTree();
    bool iscompleteTree(BinaryNode *node);

    int inorderSuccessor(const int &value);
    int inorderSuccessor(BinaryNode *node, const int &value);
    int goLeft(BinaryNode *node);

private:

    // copyTree used for copy constructor
    void copyTree (BinaryNode *treePtr, BinaryNode *&newTreePtr) const;

    // destroyTree used for destructor
    void destroyTree (BinaryNode *&treePtr);

    // findHeight used for getHeight
    int findHeight (BinaryNode *node);

    // find number of nodes
    int countNodes (BinaryNode *node, int &num);

    BinaryNode* insert (BinaryNode *&node, const int &newEntry);

    // deleteNode, deleteNodeItem, processLeftmost used for remove
    bool deleteNode (BinaryNode *node, const int &entry);
    bool deleteNodeItem (BinaryNode * &nodePtr);
    void processLeftmost (BinaryNode *&nodePtr, int &treeItem);

    // traversing
    void preorder (BinaryNode *node);
    void inorder (BinaryNode *node);
    void postorder (BinaryNode *node);
    void levelorder (BinaryNode *node, const int &level);

    void span (BinaryNode *node, const int &a, const int &b, int &result);

    void mirror(BinaryNode *node);

    //properties
    BinaryNode *root;
    int height;
    int numNodes;

};


#endif //ASSİGNMENT_2_BINARYSEARCHTREE_H
