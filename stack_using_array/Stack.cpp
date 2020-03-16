#include "Stack.h"
#include <iostream>
using namespace std;
// constructors.....
template<typename T>
Stack<T>::Stack(T element)
{
  container= new T[5];
  container[0]=element;
  size=1;
  capacity=5;
}
template<typename T>
Stack<T>::Stack(T*elements, int size)
{
   container= new T[size];
   for (int i=0; i<size ; i++){
         *(container+i)=*(elements+i);    
   }
   top=container+size-1;     
   capacity=size;
   this->size=size;      
}


// functions...
template<typename T>
T Stack<T>::get_top()
{
    return *(top);    
}
template<typename T>
void Stack<T>::display(){
      T *pointer=top;
       while (pointer>=container){
             cout << *(pointer) << endl ;
             pointer-=1;
       } 
        cout << "================================" << endl ;   
}
template <typename T>
void Stack<T>::push(T element)
{
   if (capacity==size){
        increase_capacity();    
   }   
   container[size]=element;
   top=container+size;
   size++;
      
}
template <typename T>
void Stack<T>::increase_capacity()
{
      T* temp= new T[capacity*2];
       for (int i=0; i<size;i++){
             temp[i]=container[i];       
       }
        container=temp;
        temp=nullptr;
        capacity=capacity*2;        
}
template<typename T>
void Stack<T>::pop()
{
    size--;
    top=container+size-1;     
}
template<typename T>
T Stack<T>::peek(int index){
    try{
         if (index<0 || index>=size){
              throw (string)"Out of bounds ";     
         }
         return *(container+(size-1-index));
    }
     catch(string e){
         cout << e << endl;
         exit(0);
     }     
}
template <typename T>
bool Stack<T>::is_full(){
    if (size==capacity){
        return true;   
     } 
     return false;     
}
template <typename T>
bool Stack<T>::is_empty(){
    if (size==0){
        return true;   
     } 
     return false;     
}


// destructors....
template<typename T>
Stack<T>::~Stack()
{
}

