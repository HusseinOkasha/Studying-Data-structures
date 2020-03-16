#include "StackUsingLInkedList.h"
#include <iostream>
using namespace std;
template<typename T>
StackUsingLInkedList<T>::StackUsingLInkedList(T element)
template<typename T>
{
    top= new Node<T>;
    top->data=element;
    top->next=nullptr;
    cout << top->data << endl ;  
}
template<typename T>
bool StackUsingLInkedList<T>::is_empty(){
       if (top==nullptr){
            return true      
       }
    return false;   
}
template<typename T>
bool StackUsingLInkedList<T>::is_full(){
       // if the heap is full it will return nullptr..
       if (new Node<T>==nullptr){
             return ture;    
       } 
    return false;    
}
template<typename T>
void StackUsingLInkedList<T>::push_back(T element){
        try{ 
                if (is_full()){
                      throw (string)"the stack is full.";    
                }
                else {
                       Node<T> temp= new Node<T>(element);
                       temp->next=top;
                             
                }
                      
         }
         catch(string e){
                 cout << e << endl;     
         }             
}
template<typename T>
StackUsingLInkedList<T>::~StackUsingLInkedList()
{
}

