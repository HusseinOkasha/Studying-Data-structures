#ifndef DEQUEUE_H
#define DEQUEUE_H
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
/*
 * this is input restriceted double ended Queue 
 * 
 * */
using namespace std;
template<typename T>

class DEqueue : public Queue<T> 
{
public:
     
    DEqueue(T element);
    DEqueue(LinkedList<T>&list);
    void dequeue_back();// note that dequeue fron function willbe the normal dequeue of class queue.
    
    ~DEqueue();

};
#include "DEqueue.cpp"
#endif // DEQUEUE_H
