//
// Created by Boran Yildirim on 26.10.2016.
//

#include "BinaryNode.h"

#define NULL 0

BinaryNode::BinaryNode() {
    setData(0);
    setLeft(NULL);
    setRight(NULL);
}

BinaryNode::BinaryNode(const int &entry) {
    setData(entry);
    setLeft(NULL);
    setRight(NULL);
}

BinaryNode::BinaryNode(const int &entry, BinaryNode *bnleft, BinaryNode *bnright) {
    setData(entry);
    setLeft(bnleft);
    setRight(bnright);
}

int BinaryNode::getData() {
    return data;
}

void BinaryNode::setData(const int &newData) {
    data = newData;
}

BinaryNode *& BinaryNode::getLeft() {
    return left;
}

void BinaryNode::setLeft(BinaryNode *node) {
    left = node;
}

BinaryNode *& BinaryNode::getRight() {
    return right;
}

void BinaryNode::setRight(BinaryNode *node) {
    right = node;
}
