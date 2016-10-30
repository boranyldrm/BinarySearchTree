#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree tree(41);
    tree.add(13);
    tree.add(45);
    tree.add(10);
    tree.add(15);
    tree.add(44);
    tree.add(46);
    tree.add(55);
    tree.add(20);
    tree.add(80);
    tree.add(52);
    tree.add(48);
    tree.add(19);
    tree.add(77);
    tree.add(39);
    tree.add(28);
    tree.add(50);

    tree.postorderTraverse();
/*
    cout << "***** Preorder *****" << endl;
    tree.preorderTraverse();

    cout << "***** Inorder *****" << endl;
    tree.inorderTraverse();

    cout << "*****Postorder*****" << endl;
    tree.postorderTraverse();

    tree.trim(21, 56);
    tree.inorderTraverse();
*/
    return 0;
}