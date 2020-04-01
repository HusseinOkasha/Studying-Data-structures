//============================================================================
// Name        : Binary_Search_tree.cpp
// Author      : Hussein Okasha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

int main() {
	int array[11]={20,15,10,16,5,13,4,9,11,12,21};
    Binary_Search_Tree *tree= new Binary_Search_Tree(array, 11) ;
    cout << "Before deleting" << endl ;
    tree->inorder_traversal(tree->root);
    tree->delete_value(20);
    cout << "\nAfter deleting" << endl ;
    tree->inorder_traversal(tree->root);
	return 0;
}
