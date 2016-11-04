//
// Created by Boran Yildirim on 26.10.2016.
//

#ifndef ASSİGNMENT_2_BINARYNODE_H
#define ASSİGNMENT_2_BINARYNODE_H


class BinaryNode {
public:
    //constructors
    BinaryNode ();
    BinaryNode (const int &entry);
    BinaryNode (const int &entry, BinaryNode *bnleft, BinaryNode *bnright);

    // accessors and mutators
    int getData();
    void setData(const int &newData);
    BinaryNode *& getLeft();
    void setLeft(BinaryNode *node);
    BinaryNode *& getRight();
    void setRight(BinaryNode *node);
private:

    // properties
    int data;
    BinaryNode *left;
    BinaryNode *right;

};


#endif //ASSİGNMENT_2_BINARYNODE_H