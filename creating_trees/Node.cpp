#include "Node.h"
#include <iostream>
using namespace std;


// constructors.....
template <typename T>
Node<T>::Node()
{
    left_child=nullptr;
    right_child=nullptr;
    
}
template <typename T>
Node<T>::Node(T data){
     left_child=nullptr;
     right_child= nullptr;
     this->data=data; 
}
template <typename T>
Node<T>::Node(Node<T>*right_child, Node<T>*left_child , T data){
        this->right_child= right_child;
        this->left_child= left_child ;
        this-> data= data;    
}
/*===========================================================================================================*/

// getters.....
template <typename T>
Node <T>* Node<T>::get_left_child(){
      return left_child;    
}

template <typename T>
Node <T>* Node<T>::get_right_child(){
      return right_child;    
}

template <typename T>
T Node<T>::get_data(){
        return data;         
}
/*===========================================================================================================*/

// setters......
template <typename T>
void Node<T>::set_right_child(Node<T>*node){
        this->right_child=node;    
}

template <typename T>
void Node<T>::set_left_child (Node<T>*node ){
         this->left_child=node;    
}

template <typename T>
void Node<T>::set_data(T data){
        this->data=data;    
}
/*===========================================================================================================*/

// destructors.......
template <typename T>
Node<T>::~Node()
{
}

