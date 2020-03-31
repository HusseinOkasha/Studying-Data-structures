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
	int array[5]={10,5,70,80,56};
    cout << "Bom" << endl ;
    Binary_Search_Tree *tree= new Binary_Search_Tree(array, 5) ;
    cout << tree->root->data << endl ;
	return 0;
}
