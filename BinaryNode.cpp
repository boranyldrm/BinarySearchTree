//
// Created by Boran Yildirim on 26.10.2016.
//

#include "BinaryNode.h"

#define NULL 0

BinaryNode::BinaryNode() {
    data = NULL;
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(const int &entry) {
    data = entry;
    left = NULL;
    right = NULL;
}

BinaryNode::BinaryNode(const int &entry, BinaryNode *bnleft, BinaryNode *bnright) {
    data = entry;
    left = bnleft;
    right = bnright;
}

bool BinaryNode::add(const int &entry) {
    if (data == entry)
        return false;
    else if (data > entry) {
        if (left == NULL) {
            left = new BinaryNode(entry);
            return true;
        }
        else
            return left->add(entry);
    }
    else if (data < entry) {
        if (right == NULL) {
            right = new BinaryNode(entry);
            return true;
        }
        else
            return right->add(entry);
    }
    return false;
}
