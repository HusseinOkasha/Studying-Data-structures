/*
 * 
 * this is queue using linked list..... 
 * 
 * */
 
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "LinkedList.h"
using namespace std;
 
template <typename T>
class Queue
{    
private:
LinkedList<T>list;    
public:
    LinkedList<T>container;
    Queue(LinkedList<T>&list);
    void dequeue();
    ostream &operator<<(ostream &out );
    void enqueue(T element);
    ~Queue();

};
#include "Queue.cpp"
#endif // QUEUE_H
