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
    Node* current =root;
    Node* pervious=nullptr;
    while (current != nullptr){
           if (current->cal_height_left(current) - current->cal_height_right(current)>1){
                   
                  if (current->left_child->height_left- current->left_child->height_right<0)
                   {
                        cout << "LR rotation for "   << endl ;
                        lr_rotation(current , pervious);
                        
                        
                   }
                   else 
                   {
                        cout << "LL rotation" << current->data << endl ;
                        ll_rotation(current , pervious);
                        
                   }
           }
           else if (current->cal_height_left(current)-current->cal_height_right(current)<-1)
            {     
                   if (current->right_child->height_left- current->right_child->height_right>0)
                   {
                        cout << "RL rotation..." << current->data<< endl ;
                        rl_rotation(current , pervious);
                        
                   }
                   else
                   {
                         cout << "RR rotation" << current->data<< endl ; 
                         rr_rotation(current , pervious);
                        
                   }
                   
            }  
            pervious=current; 
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

void Tree::ll_rotation(Node* root , Node* pervious)
{
     Node* temp1=root->left_child;
     Node* temp2=temp1->right_child;
     temp1->right_child=root;
     root->left_child=temp2;
     
     //in case the unbalanced node is the root node of the whole tree.
     if (root==this->root){
         this->root=temp1;    
     }
     root=temp1;
     if (pervious!=nullptr)
    {
            if (root->data < pervious->data){
                    pervious->left_child=root;     
            }
            else{
                    pervious->right_child=root;    
            }
    }
     
}
void Tree::rr_rotation(Node* root , Node* pervious)
{   
    Node* temp1 =root->right_child;
    Node* temp2=temp1->left_child;
    temp1->left_child=root;
    root->right_child=temp2;
    
    //in case the unbalanced node is the root node of the whole tree.
    if (root==this->root){
          this->root=temp1;     
    }
    root=temp1;
     if (pervious!=nullptr)
    {
            if (root->data < pervious->data){
                    pervious->left_child=root;     
            }
            else{
                    pervious->right_child=root;    
            }
    }
}
void Tree::rl_rotation(Node* root , Node* pervious)
{
    Node* temp1= root->right_child->left_child ;
    Node* temp2=temp1->left_child;
    Node* temp3=temp1->right_child;
    temp1->left_child=root;
    temp1->right_child=root->right_child;
    root=temp1;
    root->left_child->right_child=temp2;
    root->right_child->left_child=temp3;
    
    //in case the unbalanced node is the root node of the whole tree.
    if (this->root= root->left_child){
           this->root=root;    
    }
    if (pervious!=nullptr)
    {
            if (root->data < pervious->data){
                    pervious->left_child=root;     
            }
            else{
                    pervious->right_child=root;    
            }
    }
    
}
void Tree::lr_rotation(Node* root , Node* pervious)
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
    if (this->root= temp4)
    {
        this->root=root;    
    }
    if (pervious!=nullptr)
    {
            if (root->data < pervious->data){
                    pervious->left_child=root;     
            }
            else{
                    pervious->right_child=root;    
            }
    }
    
}
void Tree::delete_key(int key){
        Node* current =root;
        Node* pervious=nullptr;
        while (current!=nullptr)
        {
                if (current->data==key)
                {
                    break;
                }
                else if (current->data < key)
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
       if (current==nullptr)
       {
           cout << "Your key doesn't exist.." << endl ;
       }
       else
       {
                Node ** to_be_connected;
                if (current->data < pervious->data)
                {
                        to_be_connected=&pervious->left_child;
                  
             
                }
                else
                {
                        to_be_connected=&pervious->right_child;     
                }
                if (current->left_child!=nullptr && current->right_child != nullptr)
                {
                 
                        Node* temp_left_child=current->left_child;
                        Node* temp=current->right_child;
                        *(to_be_connected)=current->right_child;
                        while (temp->left_child!=nullptr)
                        {
                                temp=temp->left_child;  
                        }
                        temp->left_child=temp_left_child;
    
                }
                else if (current->left_child!=nullptr && current->right_child==nullptr)
                {
                        *(to_be_connected)=current->left_child;   
                }   
                else if (current->left_child ==nullptr && current->right_child!=nullptr)
                {
                        *(to_be_connected)=current->right_child;
                }
                else if(current->left_child==nullptr && current->right_child== nullptr) 
                {
                        *(to_be_connected)= nullptr;
                  
                } 
                delete current;
                adapt_tree(key);
       }
}     

//destructors....
Tree::~Tree()
{
}

