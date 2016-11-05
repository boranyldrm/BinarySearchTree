#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree tree(5);
    tree.add(3);
    tree.add(8);
    tree.add(2);
    tree.add(4);
    tree.add(6);
    tree.add(10);
    /*
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
    tree.add(50);*/

    cout << "***** Inorder *****" << endl;
    tree.inorderTraverse();

    cout << endl << endl;
    tree.mirror();
    tree.inorderTraverse();

    cout << endl << endl;
    tree.mirror();
    tree.inorderTraverse();
/*
    cout << "***** Preorder *****" << endl;
    tree.preorderTraverse();

    cout << "***** Inorder *****" << endl;
    tree.inorderTraverse();

    cout << "***** Postorder *****" << endl;
    tree.postorderTraverse();

    cout << "***** Levelorder" << endl;
    tree.levelorderTraverse();
*/
    return 0;
}