//
// Created by hussein on 2/23/21.
//

#ifndef RED_BLACK_TREE_NODE_H
#define RED_BLACK_TREE_NODE_H

using namespace std;

class Node {
public:
    // Attributes..
    Node* l_child, *r_child , *parent;
    int val;
    bool red;


    //constructors....
    Node();
    Node(int x );
    Node(Node* root);


    //destructors
    ~Node();

};

#endif //RED_BLACK_TREE_NODE_H
