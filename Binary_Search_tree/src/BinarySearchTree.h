/*
 * BinarySearchTree.h
 *
 *  Created on: Mar 31, 2020
 *      Author: hussein
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include "Node.h";
using namespace std;

class Binary_Search_Tree {
public:
	Node *root;
	Binary_Search_Tree(int *keys, int size);
	Binary_Search_Tree();
	Node* search(int key);
	bool insert(int key);

    ~Binary_Search_Tree();
};

#endif /* BINARYSEARCHTREE_H_ */
