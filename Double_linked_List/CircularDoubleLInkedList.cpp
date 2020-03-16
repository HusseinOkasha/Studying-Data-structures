#include "CircularDoubleLInkedList.h"
#include <iostream>
using namespace std;
template<typename T>
CircularDoubleLInkedList<T>::CircularDoubleLInkedList(int *elements , int numberOfELements)
:size(numberOfELements){
     this->head = new Node <T>(*elements);
     this->head->pervious= nullptr;
     Node<T>*current=head;
     Node<T>*next;
    for (int i=1; i<numberOfELements ;i++ )
    {
         next= new Node<T> (*(elements+i)); 
         current->next= next;
         next->pervious=current;
         current=next;        
    }
    this->last=current;
    this->head->pervious=last;
    this->last->next=head;
      
}
template<typename T>
void CircularDoubleLInkedList<T>::display(){
       Node<T>*pointer=this->head;
       if (head!=nullptr){
           cout << this->head->data << endl ;
           pointer=pointer->next;
       } 
       while (pointer!=nullptr && pointer!=head){
               cout << pointer->data << endl;
               pointer=pointer->next;       
       }    
       cout << "================================================ " << endl ; 
}
template <typename T>
Node<T>* CircularDoubleLInkedList<T>::begin()
{
      return head;    
}
 
template <typename T>
Node<T>* CircularDoubleLInkedList<T>::end()
{
      return last;    
} 
template <typename T>
 void CircularDoubleLInkedList<T>::insert(int index, T element){
         Node<T>*inserted=new Node<T>(element);
  try{
        if (index==0){
              inserted->next=head;
              inserted->pervious=last;
              last->next=inserted;
              head->pervious=inserted;
              head=inserted;
          }
           else if (index==size){
                inserted->next=head;
                inserted->pervious=last;
                last->next=inserted;
                last=inserted;
                head->pervious=inserted;  
           }
            else if (index>size){
                   throw (string) "Bad location";
            } 
           else {
                Node<T>*pointer=head;
                for(int i=0; i<index-1;i++){
                      pointer=pointer->next;
                 }
                 inserted->pervious=pointer;
                 inserted->next=pointer->next;
                 pointer->next->pervious=inserted;
                 pointer->next=inserted;    
                      
           }
           size++; 
    }
     catch (string e) {
             cout << e << endl;
     }  
         
}
template<typename T>
void CircularDoubleLInkedList<T>::erase(int index, int numberOfElements ){
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
                        head->pervious=last;
                        last->next=head; 
                }
                else {
                        head=nullptr;
                        last=nullptr;             
                }
        }
        else if (last==end && head!=begin){
                last=begin->pervious;
                last->next=head;
                 head->pervious=last;          
        }
     
        size--;    
} 
template<typename T>
CircularDoubleLInkedList<T>::~CircularDoubleLInkedList()
{
}

