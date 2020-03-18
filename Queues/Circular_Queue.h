#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include "Queue.h"
#include <iostream>
using namespace std;

template<typename T>
class Circular_Queue:public Queue<T> 
{
private:
T* begin;// it will point to the physical begainning of the array...
T* end ; // it will point to the physical end of the array....        
public:
    
    Circular_Queue(T element);
    Circular_Queue(T* element, int size);
    virtual void enqueue(T element );
    virtual void dequeue();
    virtual void increase_capacity();
    ostream&operator<<( ostream &out);
    T* get_begin();
    T* get_end();
    ~Circular_Queue();

};
#include "Circular_Queue.cpp"
#endif // CIRCULAR_QUEUE_H
