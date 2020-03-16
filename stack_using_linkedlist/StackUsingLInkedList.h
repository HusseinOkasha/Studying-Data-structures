#ifndef STACKUSINGLINKEDLIST_H
#define STACKUSINGLINKEDLIST_H
#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
template <typename T>
class StackUsingLInkedList
{
private:
Node<T>* top;   
public:
     // constructors...
    StackUsingLInkedList(T element );
    
    //functions.....
    void push_back(T element);
    void pop();
    void set_top(Node<T>* top);
    Node<T>* get_top();
    bool is_full();
    bool is_empty();
    
    // destructors....
    ~StackUsingLInkedList();

};
#include "StackUsingLInkedList.cpp"
#endif // STACKUSINGLINKEDLIST_H
