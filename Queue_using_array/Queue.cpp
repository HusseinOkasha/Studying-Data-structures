#include "Queue.h"
#include <iostream>
using namespace std;
template<typename T>
Queue<T>::Queue(T element)
:size(1),capacity(5){
  first= new T[5];
  first[0]=element;
   last=first+1;  
}
template<typename T> 
Queue<T>::Queue(T *elements, int numberOfElements )
:size(numberOfElements),capacity(numberOfElements+1){
        first= new T[numberOfElements+1];
        for (int i=0; i< numberOfElements;i++){
               first[i]=elements[i];     
        }
         last=(first+numberOfElements);    
}
template<typename T> 
T* Queue<T>::get_begin(){
      return first;     
}
template<typename T> 
T* Queue<T>::get_end(){
     return last;   
}
template<typename T> 
int Queue<T>::get_size(){
      return this->size;    
}
template<typename T> 
int Queue<T>::get_capacity(){
      return this->capacity;    
}
template<typename T>
ostream &operator<<(ostream &out, Queue<T> &q){
            
            for (auto it=q.get_begin(); it!=q.get_end(); it++){
                    out <<*it  << " " ;      
            }     
         return out;   
}
template<typename T> 
Queue<T>::~Queue()
{
}

