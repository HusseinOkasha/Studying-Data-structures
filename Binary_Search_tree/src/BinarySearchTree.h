/*
 * BinarySearchTree.h
 *
 *  Created on: Mar 31, 2020
 *      Author: Hussein Okasha
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <iostream>
#include "Node.h"
using namespace std;

class Binary_Search_Tree {
public:
	//Attributes...
	Node *root;

	//Constructors....
	Binary_Search_Tree(int *keys, int size);
	Binary_Search_Tree();

	//Functions
	Node* search(int key);
	bool insert(int key);
    void inorder_traversal(Node*root);
    void delete_value(int key);
    void connect_tree(Node* right,Node* left);// connecting nodes after deletion...
	//Destructors....
    ~Binary_Search_Tree();
};

#endif /* BINARYSEARCHTREE_H_ */
