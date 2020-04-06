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
                   
                  if (current->left_child->height_left- current->left_child->height_right<0)
                   {
                        cout << "LR rotation" << endl ;
                        lr_rotation(current);
                        
                        
                   }
                   else 
                   {
                        cout << "LL rotation" << endl ;
                        ll_rotation(current);
                        
                   }
           }
           else if (current->cal_height_left()-current->cal_height_right()<-1)
            {     
                   if (current->right_child->height_left- current->right_child->height_right>0)
                   {
                        cout << "RL rotation..." << endl ;
                        rl_rotation(current);
                        
                   }
                   else
                   {
                         cout << "RR rotation" << endl ; 
                         rr_rotation(current);
                        
                   }
                   
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
     //in case the unbalanced node is the root node of the whole tree.
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
    Node* temp1 =root->right_child;
    Node* temp2=root;
    root->right_child=root->right_child->left_child;
    root=temp1;
    root->left_child=temp2;
    //in case the unbalanced node is the root node of the whole tree.
    if (temp2==this->root){
          this->root=root;     
    }
}
void Tree::rl_rotation(Node* root)
{
    Node* temp1= root->right_child->left_child ;
    Node* temp2=temp1->left_child;
    Node* temp3=temp3->right_child;
    temp1->left_child=root;
    temp1->right_child=root->right_child;
    root=temp1;
    root->left_child->right_child=temp2;
    root->right_child->left_child=temp3;
    
    //in case the unbalanced node is the root node of the whole tree.
    if (this->root= root->left_child){
           this->root=root;    
    }
    
    
}
void Tree::lr_rotation(Node* root)
{
    Node* temp1 = root->left_child->right_child;
    Node* temp2= temp1->right_child;
    Node* temp3=  temp1->left_child;
    Node* temp4=  root;
    root=temp1;
    root->left_child=temp4->left_child;
    root->right_child=temp4;
    root->left_child->right_child=temp3;
    temp4->left_child=temp2;
    
    //in case the unbalanced node is the root node of the whole tree.
    if (this->root= temp4){
        this->root=root;    
    }
    
    
    
}
     

//destructors....
Tree::~Tree()
{
}

