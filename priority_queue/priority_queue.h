#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>
#include "Queue.h"

using namespace std;
template <typename T>
class priority_queue
{
private:
    Queue<T>*high;
    Queue<T>*medium;
    Queue<T>*low;
public:
    
    priority_queue(T* elements , int* priorities, int size);
    Queue<T>* get_high();
    Queue<T>* get_low();
    Queue<T>* get_medium(); 
    ostream &operator<<(ostream &out);
    ~priority_queue();

};
#include "priority_queue.cpp"
#endif // PRIORITY_QUEUE_H
