#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
Node<T>::Node(T element )
{
    this->data=element;
    this->next=nullptr;
    this->pervious=nullptr;
}
template<typename T>
Node<T>::Node(){
    this->next=nullptr;
    this->pervious=nullptr;
}
template<typename T>
Node<T>::~Node()
{
}

