#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
template<typename T>
class Queue
{
protected:    
    LinkedList<T>*list; 
public:
    
    Queue(LinkedList<T>&list);
    void enqueue(T element);
    void dequeue();
    void display(); 
    ~Queue();

};
#include "Queue.cpp"
#endif // QUEUE_H
