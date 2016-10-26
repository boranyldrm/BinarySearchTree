#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree tree(5);
    tree.add(9);
    tree.add(3);
    tree.add(6);
    tree.add(8);
    tree.add(4);
    tree.add(1);
    tree.add(7);

    cout << "***** Preorder *****" << endl;
    tree.preorderTraverse();

    cout << "***** Inorder *****" << endl;
    tree.inorderTraverse();

    cout << "*****Postorder*****" << endl;
    tree.postorderTraverse();

    return 0;
}