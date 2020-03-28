#include "BinaryTree.h"
#include <iostream>
using namespace std;

template <typename T>
BinaryTree<T>::BinaryTree()
{
  q= new queue<Node<T>*>;  
  root=nullptr;  
}

template <typename T>
BinaryTree<T>::BinaryTree(Node<T>root)
{
    this->root= new Node<T>(root.get_data()); 
    q= new queue<Node<T>*>;
    q->emplace(this->root);
}
template <typename T>
void BinaryTree<T>::create_tree(){
       T data ;
       int check=0;// to check if node has left and right childs -1 value means no child ....
       if (this->q->empty()){
            root = new Node<T>; 
            q->push(root);
            cout << "Enter root value: " <<endl;
            cin >> data ;
            root->set_data(data);
       }
       Node<T>*temp=this->q->front();
       while (!this->q->empty()){
               q->pop();
               cout << "Note if any of the following doesn't have a value enter -1";
               cout << "==============================================================================" << endl ;
               cout << "Is there left child...?"<< endl;
               cin   >> check;  
               if (check!=-1){
                   cout << "Enter value of the left child: " << endl;    
                   cin >> data;
                   temp->set_left_child(new Node<T>(data)) ;
                   q->push(temp);
               }  
               cout << "Is there right child....?"<< endl ;
               cin >> check;
               if (check!=-1){
                   cout << "Enter value of the right child: " << endl;    
                   cin >> data;
                   temp->set_right_child(new Node<T>(data));
                   q->push(temp);
               }
                temp=this->q->front(); 
       }  
        
 
} 
template <typename T>
Node<T>* BinaryTree<T>::get_root(){
        return root;    
}
template <typename T>
BinaryTree<T>::~BinaryTree()
{
    
}

