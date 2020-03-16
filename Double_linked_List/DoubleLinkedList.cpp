#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;
// constructors 
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(T* elements , int numberOfElements)
:size(numberOfElements){
    head = new Node <T>(*elements);
    head->pervious= nullptr;
    Node<T>*current=head;
    Node<T>*next;
    for (int i=1; i<numberOfElements ;i++ )
    {
         next= new Node<T> (*(elements+i)); 
         current->next= next;
         next->pervious=current;
         current=next;        
    }
    last=current;
      
}
// functions 
template <typename T>
void DoubleLinkedList<T>::display()
{
       Node<T>*pointer=head;
       while (pointer!=nullptr){
                 cout << pointer->data << endl ;
                 pointer=pointer->next;
       }    
       cout << "========================================================="  << endl ;
}
template <typename T>
Node<T>* DoubleLinkedList<T>::begin()
{
      return head;    
}
 
template <typename T>
Node<T>* DoubleLinkedList<T>::end()
{
      return last;    
} 

template <typename T>
void DoubleLinkedList<T>::push_back(T element)
{
     Node<T>*inserted = new Node<T>(element);
     inserted->pervious=last;
     last->next=inserted;
     last=inserted;
     size++;       
}
template <typename T>
void DoubleLinkedList<T>::push_front(T element){
       Node<T>* inserted = new Node<T>(element);
       inserted->next=head;
       head->pervious=inserted;
       head=inserted;     
       size++;
}
template <typename T>
void DoubleLinkedList<T>::insert(int index , T element )
{
    if (index==0){
        push_front(element);    
    }
     else if (index==size){
         push_back(element);  
    }
     else {
          Node<T>*pointer=head;
          Node<T>*inserted=new Node<T>(element);
          Node<T>*inserted_next;
          
          for (int i=0; i<index-1;i++){
               pointer=pointer->next;     
          }
           inserted_next=pointer->next;
           pointer->next=inserted;
           inserted->pervious=pointer;
           inserted->next=inserted_next;
           inserted_next->pervious=inserted;
    }
    size++;
}
template<typename T>
void DoubleLinkedList<T>::pop_front()
{
    head=head->next;
    head->pervious=nullptr;
    size--;
}
template<typename T>
void DoubleLinkedList<T>::pop_back()
{
    last=last->pervious;
    last->next=nullptr;
    size--;
}
template<typename T>
void DoubleLinkedList<T>::erase(int index , int numberOfElements)
{
   Node<T>*pointer=head; 
   Node<T>*begin;// to the first element to be deleted from the list.
   Node<T>*end;//    points to the last element to be deleted from the list.
   for (int i=0; i<index;i++){
         pointer=pointer->next;    
   }
    begin=pointer;
    for (int i=0; i<numberOfElements-1 ;i++){
           pointer=pointer->next;
    } 
    end=pointer;
     if (begin!=head && end !=last){
         end->next->pervious=begin->pervious;
         begin->pervious->next=end->next; 
     }
     else if(begin==head ) {
             if (last!=end){
                    head=end->next;
                    head->pervious=nullptr;
                    end->pervious=head;
             }
              else {
                   head=nullptr;
                    last=nullptr;             
              }
     }
     else if (last==end && head!=begin){
              last=begin->pervious;
              last->next=nullptr;
              last->pervious=begin->pervious;         
     }
     
    size--;    
}
template <typename T>
void DoubleLinkedList<T>::reverse(){
        Node<T>*current=this->head;
        Node<T>*next;
        Node<T>*temp;
        while (current!=nullptr){
                temp=current->next;
                current->next=current->pervious;
                current->pervious=temp;
                current=temp; 
        }
         temp=this->last;
          this->last=this->head;
          this->head=temp;   
}
// destructors 
template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
}

