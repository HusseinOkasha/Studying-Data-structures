#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
template <typename T>
class DoubleLinkedList
{
public:
 // Attributes.......    
    Node<T>*head;
    Node<T>*last;
    int size ;
 // constructors.......   
    DoubleLinkedList(T* elements, int NumberOfElements);
// functions.... 
    void display();  
    Node<T>* begin();
    Node<T>* end();
    void push_back(T element );
    void push_front(T element);
    void insert(int index , T element);
    void pop_front();
    void pop_back();
    void erase(int index, int numberOfElements); 
    void reverse();
// destructors.....   
    ~DoubleLinkedList();

};
#include "DoubleLinkedList.cpp"
#endif // DOUBLELINKEDLIST_H
