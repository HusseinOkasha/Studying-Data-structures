#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;
template<typename T>
class LinkedList
{
protected:
    Node<T>*head;
    Node<T>*last;
    int size ;   
public:
     LinkedList();
     LinkedList(int numberOfElements,T* elements );
     LinkedList(T element );
     virtual void display();
     int numberOfNodes();
     virtual void  insert (T element , int index); 
     void push_back(T element);
     virtual void erase( int index, int numberOfElements);
     bool is_sorted();
     void insert_sorted(T element);
     void reverse();
     Node<T>* begin();
     Node<T>* end();
     int get_size ();
     void append_list(LinkedList<T>list);
     void merge (LinkedList<T>list);
     bool is_loop();
     
    ~LinkedList();

};
#include "LinkedList.cpp"
#endif // LINKEDLIST_H