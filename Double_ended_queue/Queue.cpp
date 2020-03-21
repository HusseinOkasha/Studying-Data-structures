#include "Queue.h"
#include <iostream>
#include "LinkedList.h"
using namespace std;
template <typename T>
Queue<T>::Queue(LinkedList<T>&list)
{
    this->list=&list;
     
}
template<typename T>
void Queue<T>::enqueue(T element){
         list->push_back(element);     
}
template<typename T>
void Queue<T>::dequeue(){
      list->erase(0,1);    
}
template <typename T>
void Queue<T>::display(){
      list->display();    
}
template<typename T>
Queue<T>::~Queue()
{
}

