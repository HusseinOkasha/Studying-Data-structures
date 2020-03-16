#include "CircularLinkedList.h"
#include "Node.h"
#include <iostream>

using namespace std;
template<typename T>
CircularLinkedList<T>::CircularLinkedList(int numberOfElements , T *elements )
:LinkedList<T>(numberOfElements , elements){
      this->last->next=this->head;
}
template<typename T>
void CircularLinkedList<T>::display(){
    Node<T>*pointer;
    pointer=this->head;
    if (pointer!=nullptr){
         cout << pointer->data << endl ;
         pointer=pointer->next;      
    }
    while (pointer!=nullptr && pointer!=this->head){
             cout << pointer->data << endl ;
             pointer=pointer->next;   
    }
     cout << "========================================================="  << endl ;
}
template <typename T>
void CircularLinkedList<T>::insert(T element , int index){
        Node<T>*pointer_iteration=this->head;
        Node<T>*inserted=new Node<T>;    
        inserted->data=element;
        Node<T>*pervious=this->head;   
        if (index==this->size){
            this->push_back(element);   
            this->last->next=this->head; 
        }
        else if (index==0){
                  inserted->next=this->head;
                  this->head=inserted;
                   this->last->next=this->head;      
        }
        else{
                for (int i=0; i<this->size ; i++) {
                        if (i==index){
                            pervious->next=inserted;
                            inserted->next=pointer_iteration;
                            break;
                        }
                        pervious=pointer_iteration;
                        pointer_iteration=pointer_iteration->next;
                }
         }
         this->size++;      
} 
template <typename T>
void CircularLinkedList<T>::erase(int index , int numberOfElements ){
         Node<T>*pointerIterator=this->head;
         Node<T>*pointerBegin;//points to the pervious element of the first index to be erased 
         Node<T>*pointerEnd;// points to the element following the last element to be erased 
         if (index==0){
                for (int i=0; i<numberOfElements;i++ ){
                        pointerIterator=pointerIterator->next;    
                }
                 this->head=pointerIterator;
                 this->last->next=this->head;     
         }
         else{ 
                for (int i=0; i<index-1;i++){
                    pointerIterator=pointerIterator->next;    
                }
                pointerBegin=pointerIterator;
                for (int i=0; i<=numberOfElements;i++ ){
                        pointerIterator=pointerIterator->next;    
                }
                pointerEnd=pointerIterator;
                pointerBegin->next=pointerEnd;
                if (pointerIterator==this->head){
                    this->last=pointerBegin;    
                }
         }
           
}
template<typename T>
void CircularLinkedList<T>::reverse(){
    Node<T>*current=this->head;
    Node<T>*pervious=this->last;
    Node<T>*next=current->next;
    while (true){
            next=current->next;
            current->next=pervious;
            pervious=current;
            current=next;
            if (current==this->head){
                 break;  
            }
    }  
    Node<T>*temp=this->last;
    this->last=this->head;
    this->head=temp;      
}
template<typename T>
CircularLinkedList<T>::~CircularLinkedList()
{
}

