#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "Node.h"
   
#include <queue>
using namespace std;

template <typename T>
class BinaryTree
{
private:
   Node<T>* root;
   queue<Node<T>*>*q;    
public:
    
    BinaryTree();
    BinaryTree(Node<T>root);
    Node<T>* get_root();
    void create_tree();
    ~BinaryTree();

};
#include "BinaryTree.cpp"
#endif // BINARYTREE_H
