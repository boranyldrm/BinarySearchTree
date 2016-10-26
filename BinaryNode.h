//
// Created by Boran Yildirim on 26.10.2016.
//

#ifndef ASSİGNMENT_2_BINARYNODE_H
#define ASSİGNMENT_2_BINARYNODE_H


class BinaryNode {
private:
    BinaryNode ();
    BinaryNode (const int &entry);
    BinaryNode (const int &entry, BinaryNode *bnleft, BinaryNode *bnright);

    bool add (const int &entry);

    int data;
    BinaryNode *left;
    BinaryNode *right;

    friend class BinarySearchTree;
};


#endif //ASSİGNMENT_2_BINARYNODE_H
