#include "Node.h"
#include <iostream>
using namespace std;
Node::Node()
{
    right_child=nullptr;
    left_child=nullptr;
    height_left=0;
    height_right=0;
    
}
Node::Node (int key)
:data(key){
    right_child=nullptr;
    left_child=nullptr;
    
    height_left=0;
    height_right=0;
    
    
}
int Node::cal_height_left(Node * root){
        Node* current= root;
        int counter=0;
        if (current->left_child==nullptr){
              counter++;
              height_left=counter;
              return counter;  
        }
        while (current != nullptr){
                 counter++;
                 if (current->left_child!=nullptr)
                 {
                     current=current->left_child;      
                 }
                 else if(current->right_child!=nullptr) 
                 {
                     current=current->right_child;  
                 }
                 else 
                 {
                      break;   
                 }
                
        } 
        
    height_left=counter;
    return counter;
    
}
int Node::cal_height_right(Node * root){
    Node *current= root;
    int counter=0;
    if (current->right_child==nullptr){
           counter++;
           height_right=counter;
            return counter;
    }
    while (current!=nullptr){
                counter++;
                 if (current->right_child!=nullptr)
                 {
                     current=current->right_child;      
                 }
                 else if(current->left_child!=nullptr) 
                 {
                     current=current->left_child;  
                 }
                 else 
                 {
                      break;   
                 }
    }
    height_right=counter;
    return counter;
}
int Node::get_left_height(){
       return height_left;   
}
int Node::get_right_height(){
       return height_right;     
}
Node::~Node()
{
}

    