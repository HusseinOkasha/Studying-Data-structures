#include "Tree.h"
#include <cmath>
#include <iostream>
using namespace std;

//constructors.....
Tree::Tree(int key )
{
   root = new Node(key);    
   
    
}
Tree::Tree(int *keys){
    
} 
//functions...
bool Tree::insert(int key){
        Node* current =root;
        Node* pervious=nullptr;
        Node* inserted= new Node(key);
        if (search(key)==nullptr){
              
                while (current!=nullptr)
                {
                        if (current->data < key)
                        {
                            pervious=current;
                            current=current->right_child;
                        }
                        else
                        {
                            pervious=current;
                            current=current->left_child;
                        }
                }
                if (key > pervious->data)
                {
                    pervious->right_child=inserted;
                    pervious->height_right++;

                }
                else
                {
                    pervious->left_child=inserted;
                    pervious->height_left++;
                }
                 adapt_tree(key);
                
                
                return true;
        }
        return false;
}
Node* Tree::search(int key){
         Node* current =root;
        Node* pervious=nullptr;
        while (current!=nullptr){
            if (current->data==key){
                return current;
            }
            else if (current->data < key){
                pervious=current;
                current=current->right_child;
            }
            else {
                pervious=current;
                current=current->left_child;
            }
     }
     return nullptr;
}    

void Tree::adapt_tree(int key)
{
    Node * current =root;
    
    while (current != nullptr){
           if (current->cal_height_left() - current->cal_height_right()>1){
                    ll_rotation(current);
            }
          
            if (current->data< key){
                current= current->right_child;        
            } 
            else if (current->data > key){
                  current=current->left_child;     
            }
            else if (current->data==key){
                    break;
            }  
    }
    
}

void Tree::ll_rotation(Node* root)
{
     Node* temp;
     Node* temp2;
     temp=root->left_child->right_child;
     root->left_child->right_child=root;    
     temp2=root->left_child;
     root->left_child=temp;
     if (root==this->root){
        this->root=temp2;    
        root=temp2;
     }
     else{
          root=temp2;    
     }
     
}
void Tree::rr_rotation(Node* root)
{
    
}
void Tree::rl_rotation(Node* root)
{
    
}
void Tree::lr_rotation(Node* root)
{
    
}
     

//destructors....
Tree::~Tree()
{
}

