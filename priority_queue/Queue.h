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
    Queue();
    Queue(LinkedList<T>&list);
    void enqueue(T element);
    void dequeue();
    void display(); 
    int get_size();
    ~Queue();

};
#include "Queue.cpp"
#endif // QUEUE_H
