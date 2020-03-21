#include "DEqueue.h"
#include <iostream>
using namespace std;

template<typename T>
DEqueue<T>::DEqueue(T element)
:Queue<T>(element){
}

template<typename T>
DEqueue<T>::DEqueue(LinkedList<T>&list)
:Queue<T>(list){    
}

template<typename T>
void DEqueue<T>::dequeue_back(){
      this->list->erase(this->list->get_size()-1,1);    
}
template<typename T>
DEqueue<T>::~DEqueue()
{
}

