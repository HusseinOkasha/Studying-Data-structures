#include "Circular_Queue.h"
#include <iostream>
using namespace std;
template <typename T> 
Circular_Queue<T>::Circular_Queue(T element)
:Queue<T>(element){
      begin=this->first;
      end=this->first+this->capacity-1; 
 
}
template<typename T>
Circular_Queue<T>::Circular_Queue(T* elements, int size)
:Queue<T>(elements, size){
  begin=this->first;
  end=this->last-1; // as last points to just after the last element.  
}

template <typename T>
void Circular_Queue<T>::increase_capacity(){
       T *temp= new T[this->capacity*2+1];
          for (int i=0; i<this->size;i++){
                 temp[i]=*(this->first+i);      
          }
          this->capacity=this->capacity*2;
           delete [] this->first;
           this->first=temp;
           this->last=temp+this->size;         
           temp=nullptr;
           begin=this->first;
           end=this->first+this->capacity-1;
}

template <typename T>
void Circular_Queue<T>::dequeue(){
          
    if (this->is_empty()!=true){ 
            if (this->first==end && this->last==end){
                this->first=begin;
                this->last=begin;
            }  
            else if (this->first==end){
                this->first=begin;     
            }
            else{
                this->first++;
            }
            
            this->size--;      
    }
}
template <typename T>
T* Circular_Queue<T>::get_begin(){
     return begin;
    
}
template<typename T>
T* Circular_Queue<T>::get_end(){
     return end;
    
}
template<typename T>
ostream&operator<<( ostream &out, Circular_Queue<T> &q){
     for (auto it=q.get_begin(); it!=q.get_end(); it++){
                    out <<*it  << " " ;      
            }     
         return out;   
}
template<typename T>
Circular_Queue<T>::~Circular_Queue()
{
    
}

