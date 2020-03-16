#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
template<typename T>
class CircularLinkedList : public LinkedList<T>
{
public:
    CircularLinkedList(int numberOfElements , T *elements );
    virtual void display();
    virtual void insert(T element , int index);
    virtual void erase(int index, int numberOfElements);
    virtual void reverse();    
    ~CircularLinkedList();

};
#include "CircularLinkedList.cpp"
#endif // CIRCULARLINKEDLIST_H
