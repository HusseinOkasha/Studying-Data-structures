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
:size(numberOfElements),capacity(numberOfElements){
        first= new T[numberOfElements+1];
        for (int i=0; i< numberOfElements;i++){
               first[i]=elements[i];     
        }
         last=(first+numberOfElements);    
}
template<typename T> 
T* Queue<T>::get_first(){
      return first;     
}
template<typename T> 
T* Queue<T>::get_last(){
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
            
            for (auto it=q.get_first(); it!=q.get_last(); it++){
                    out <<*it  << " " ;      
            }     
         return out;   
}
template <typename T>
bool Queue<T>::is_empty(){
      if (size==0){
           return true ;    
      } 
    return false;   
}
template <typename T>
bool Queue<T>::is_full(){
        if (capacity==size){
              return true;      
        }    
      return false;  
}
template <typename T>
void Queue<T>::increase_capacity(){
         T *temp= new T[capacity*2+1];
          for (int i=0; i<size;i++){
                 temp[i]=*(first+i);      
          }
           capacity=capacity*2;
           delete [] first;
           first=temp;
           last=temp+size;         
           temp=nullptr;
}
template <typename T>
void Queue<T>::enqueue(T element){
      if (capacity==size){
           increase_capacity();      
      }
     *(last)=element;    
       size++; 
       last+=1;
}
template<typename T> 
void Queue<T>::dequeue(){
        try{
             if (is_empty()==true){
                 throw (string) "The Queue is already empty";    
             }
             for (int i=1; i<size;i++){
                   *(first+i-1)=*(first+i);     
             }
             last--;
             size--;
                       
        }
        catch(string e){
               cout << e << endl ;     
        }    
}
template<typename T> 
Queue<T>::~Queue()
{
}

