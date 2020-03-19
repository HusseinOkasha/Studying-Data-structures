#include <iostream>
#include "Node.h"
using namespace std;
template<typename T>
Node<T>::Node(T data){
        this->data=data;
        this->next=nullptr;
}
template <typename T>
Node<T>::Node(){
         this->next=nullptr;
          
}
template<typename T>
Node<T>::~Node()
{
  
}
