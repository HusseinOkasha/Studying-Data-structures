//
// Created by hussein on 12/23/20.
//

#include "Node.h"
#include<bits/stdc++.h>
using namespace std;

Node::Node()
        :l_child(NULL),r_child(NULL),parent(NULL),val(0),red(true){

}

Node::Node(int x)
        :l_child(NULL),r_child(NULL),parent(NULL),val(x),red(true){

}
Node::Node(Node* root){
    if(root!=NULL){
        this->l_child=root->l_child;
        this->r_child=root->r_child;
        this->red=root->red;
        this->parent=root->parent;
        this->val=root->val;
    }
}

Node::~Node(){

}