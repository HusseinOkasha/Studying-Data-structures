/*
 * BinarySearchTree.cpp
 *
 *  Created on: Mar 31, 2020
 *      Author: Hussein Okasha
 */

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
//constructors...
Binary_Search_Tree::Binary_Search_Tree() {
	root=nullptr;
}
Binary_Search_Tree::Binary_Search_Tree(int *keys, int size) {
	  root = new Node(*keys);
	  for (int i=0; i<size; i++){
		  insert(*(keys+i));
	  }

}
/*========================================================================*/


//Functions.....
Node* Binary_Search_Tree::search(int key){
     Node* current =root;
     Node* pervious=nullptr;
     while (current!=nullptr){
    	  if (current->data==key){
    		 return current;
    	  }
    	  else if (current->data < key){
    		  pervious=current;
    		  current=current->right;
    	  }
    	  else {
    		  pervious=current;
    		  current=current->left;
    	  }
     }
     return nullptr;
}
bool Binary_Search_Tree::insert(int key){
	Node* current =root;
    Node* pervious=nullptr;
    Node* inserted= new Node(key);
	if (search(key)==nullptr){
		while (current!=nullptr){
		     if (current->data < key){
		    	  pervious=current;
		    	  current=current->right;
		      }
		      else {
		          pervious=current;
		    	  current=current->left;
		     }
		 }
		 if (key > pervious->data){
			 pervious->right=inserted;

		 }
		 else{
			 pervious->left=inserted;
		 }
		 return true;
	}
   	return false;
}
void Binary_Search_Tree::inorder_traversal(Node* root){
	if (root!=nullptr){
		inorder_traversal(root->left);
		cout <<root->data << endl ;
		inorder_traversal(root->right);
	}

}
void Binary_Search_Tree::delete_value(int key){
	Node* current =root;
	Node* pervious=nullptr;
	bool check=false;
	while (current !=nullptr){
		if (key > current->data){
			pervious=current;
			current=current->right;

		}
		else if (key < current->data) {
			pervious=current;
			current=current->left;
		}
		else if (key == current->data){
			   check=true;
			   break;
		}
	}
	if (check==true){
		if (current==root){
			connect_tree(root->right, root->left);
			root=root->right;

		}
		else{
			if (current==pervious->left){
				pervious->left=current->right;

			}
			else if (current==pervious->right) {
				pervious->right=current->right;

			}
			connect_tree(current->right, current->left);
		}

	}
}
void Binary_Search_Tree::connect_tree(Node* right, Node* left){
	 Node* current=right;
	 Node* pervious=nullptr;
	 if (current!=nullptr){
		 while (current!=nullptr){
			 pervious=current;
			 current =current->left;
		 }
		 pervious->left=left;
	 }
}
/*========================================================================*/


//Destructors...
Binary_Search_Tree::~Binary_Search_Tree() {
	// TODO Auto-generated destructor stub
}

