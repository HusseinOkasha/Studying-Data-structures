#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.h"
using namespace std;

class Tree
{
public:
    // Attributes.....
    Node * root; 
    
    
    // Constructors.....
    Tree(int * keys);
    Tree(int key);
    
    
    // functions.......
     Node* search(int key);
     bool insert(int key);
     void delete_key(int key);
     
     void adapt_tree(int key);// adapt  tree after effect of key. 
     void ll_rotation(Node* root);
     void rr_rotation(Node* root);
     void rl_rotation(Node* root);
     void lr_rotation(Node* root);
     
    //destructors  
    ~Tree();

};

#endif // TREE_H
