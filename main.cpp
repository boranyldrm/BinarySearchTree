#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree tree(15);
    tree.add(2);
    tree.add(18);
    tree.add(8);
    tree.add(16);
    tree.add(25);
    tree.add(6);
    tree.add(10);
    tree.add(4);
    tree.add(9);
    tree.add(12);
    tree.add(20);
    tree.add(22);
    tree.add(21);
    tree.add(23);
    /*tree.add(80);
    tree.add(52);
    tree.add(48);
    tree.add(19);
    tree.add(77);
    tree.add(39);
    tree.add(28);
    tree.add(50);
*/
    //cout << tree.getNumberOfNodes() << endl;

    cout << "***** Inorder *****" << endl;
    tree.preorderTraverse();
    cout << endl;
    tree.postorderTraverse();
/*
    cout << endl << endl;
    tree.mirror();
    tree.inorderTraverse();

    cout << endl << endl;
    tree.mirror();
    tree.inorderTraverse();*/
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