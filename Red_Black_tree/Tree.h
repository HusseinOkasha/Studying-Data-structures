//
// Created by hussein on 2/23/21.
//

#ifndef RED_BLACK_TREE_TREE_H
#define RED_BLACK_TREE_TREE_H

#include "Node.h"
#include<bits/stdc++.h>
using namespace std;
class Tree {
public:
    // attributes
    Node* root;

    //constructors
    Tree();
    Tree(Node*root);


    //methods
    void insert(int key);
    Node* search(int key);
    Node* erase(int key);
    void clear();
    void visualize_tree();
    void rr_rotation(Node* child);
    void rl_rotation(Node* child);
    void ll_rotation(Node* child);
    void lr_rotation(Node* child);
    void adapt_tree(Node*parent, Node*child);
    Node* get_uncle(Node* child);
    vector<vector<Node*>> level_order();
    bool is_left_child(Node* child);
    void recolor(Node* root);
    Node* get_predecessor(Node* root);
    Node* get_successor(Node* root);
    bool is_leaf_node(Node* root);
    Node*  erase_red_node(Node* to_be_erased);
    Node* erase_black_node(Node* to_be_erased);
    void adapt_after_deletion(Node* parent, Node* replacement);
    Node* get_brother(Node* child, Node* parent );


    //Destructors..
    ~Tree();



};


#endif //RED_BLACK_TREE_TREE_H
