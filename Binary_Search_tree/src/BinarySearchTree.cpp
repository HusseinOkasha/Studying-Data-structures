/*
 * BinarySearchTree.cpp
 *
 *  Created on: Mar 31, 2020
 *      Author: Hussein Okasha
 */

#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

Binary_Search_Tree::Binary_Search_Tree() {
	root=nullptr;
}

Binary_Search_Tree::Binary_Search_Tree(int *keys, int size) {
	  root = new Node(*keys);
	  for (int i=0; i<size; i++){
		  insert(*(keys+i));
	  }

}
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
Binary_Search_Tree::~Binary_Search_Tree() {
	// TODO Auto-generated destructor stub
}

