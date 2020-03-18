#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Queue.h"

#include <iostream>
using namespace std;
template <typename T>

Queue<T>::Queue(LinkedList<T>&list)
{
    this->list->head=list->begin();
    this->list->last=list->end();
}
template <typename T>
Queue<T>::~Queue()
{
}
#endif 