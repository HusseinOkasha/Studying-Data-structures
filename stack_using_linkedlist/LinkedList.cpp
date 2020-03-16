#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;
template<typename T>
LinkedList<T>::LinkedList(T element ){
        this->data=element;
        this->next=nullptr;     
}
template<typename T>
LinkedList<T>::LinkedList(int numberOfElements,T* elements )
:size{numberOfElements}{
     
     head = new Node<T>;
     head->next=nullptr;
     head->data=*(elements);
     Node<T>*pointer;
     pointer=head;
    for (int i=1; i<numberOfElements ; i++){
             last = new Node<T>;
             last->next=nullptr;
             last->data=*(elements+i);
             pointer->next=last;
             pointer=nullptr; 
             pointer=last;
    }
    
}
template<typename T>
void LinkedList<T>::display(){
       Node<T>*pointer=head;
       while (pointer!=nullptr){
                 cout << pointer->data << endl ;
                 pointer=pointer->next;
       }    
       cout << "========================================================="  << endl ;
}
template<typename T>
int LinkedList<T>::numberOfNodes(){
       
        return size;
}
template<typename T>
void LinkedList<T>::insert(T element , int index){
       Node<T>*inserted = new Node<T>(element);
       if (index<0){
            cout << " Error -ve index " << endl ;
       }
        else if (index==0){
                Node<T>*temp=new Node<T>;
                temp->data=head->data;
                temp->next=head->next; 
                head->data=inserted->data;
                head->next=temp;
                inserted=head;   
        }
        else if(index==size-1)  {
                last->next=inserted;
                last=inserted;
                 
        }
        else {
                 Node<T>*pointer=head;
                 for(int i=0; i<index; i++){
                        if (i==index-1){
                             inserted->next=pointer->next;
                             pointer->next=inserted;
                             break;
                        }
                         pointer=pointer->next;       
                 } 
        }
        size++;
        
}
template <typename T>
void LinkedList<T>::push_back(T element ){
        Node<T>*pushed= new Node<T>(element);
        last->next=pushed;
        last=pushed;
        size++;
}
template<typename T>
void LinkedList<T>::erase(int index ,int numberOfElements ){
       Node<T>*pointer=head;
       if (index==0){
            for(int i=0; i<numberOfElements;i++){
                   pointer=pointer->next;        
            }
             head=pointer;
       }
       else if (index+numberOfElements==size){
                  Node<T>*pointerLeft=head;
                 for (int i=1; i<=index-1; i++){
                        pointer=pointer->next;                  
                  }
                   last=pointer;
                   last->next=nullptr;
       } 
       else {
            Node<T>*pointerLeft=head;
            for (int i=1; i<=index-1; i++){
                  pointer=pointer->next;                  
            }
            pointerLeft=pointer;
            for (int i=index; i<=numberOfElements+index;i++){
                  pointer=pointer->next;       
            }
             pointerLeft->next=pointer;
       }
                   
       size-=numberOfElements;
}
template <typename T>
bool LinkedList<T>::is_sorted(){
       Node<T>*pointer=head;
       while (pointer->next!=nullptr){
            if (pointer->data > pointer->next->data){
                 return false;      
            }
             pointer=pointer->next;
       }
    return true ; 
} 
template<typename T>
void LinkedList<T>::insert_sorted(T element){
        
        Node<T>*shifted=new Node<T>;
        shifted->data=head->data;
        shifted->next=head->next;
        Node<T>*inserted=new Node<T>(element);
        if (inserted->data < head->data){
            inserted->next=shifted;
            head->data=inserted->data;
            head->next=inserted->next;     
        }
         else if (inserted->data >= last->data){
                  push_back(element);
         }
         else{
                Node<T>*pointer=head;
                while (pointer->next!=nullptr){
                        if (pointer->data <= inserted->data && inserted->data <= pointer->next->data ){
                            inserted->next=pointer->next;
                            pointer->next=inserted;
                            break;
                        }
                        pointer=pointer->next;
                }    
       
      }
       size++;
}
template<typename T>
void LinkedList<T>::reverse(){
       Node<T>*pointerCurrent=head;
       Node<T>*pointerNext=pointerCurrent->next;
       Node<T>*pointerPervious=pointerCurrent;
       pointerCurrent->next=nullptr;
       while (pointerNext!=nullptr){
            pointerCurrent=pointerNext;
            pointerNext=pointerCurrent->next;
            pointerCurrent->next=pointerPervious;
            pointerPervious=pointerCurrent;
      }
        
       Node<T>*temp;
       temp=last;
       last=head;
       head=temp;
        
}
template<typename T>
Node<T>* LinkedList<T>::begin(){
         return head;    
}
template<typename T>
Node<T>* LinkedList<T>::end(){
         return last;    
}
template<typename T>
void LinkedList<T>::append_list(LinkedList<T>list){
     
     last->next=list.begin();     
}
template<typename T>
void LinkedList<T>::merge(LinkedList<T>list){
           Node<T>*pointer1=head;
           Node<T>*pointer2=list.begin();
           Node<T>*pervious;
           Node<T>*temp1;
           Node<T>*temp2;
           if (pointer1->data>=pointer2->data){
                head=list.begin();
                pointer2=pointer2->next;
           }
           else{
                  pointer1=pointer1->next;
           }
            pervious=head;
            Node<T>*smaller;
           while (smaller->next!=nullptr){
                    if (pointer1->data<=pointer2->data ){
                          pervious->next=pointer1;
                          temp1=pointer1->next;
                           pervious=pointer1;
                           pointer1=temp1;
                                    
                    }
                    else if(pointer2->data<=pointer1->data ) {
                              pervious->next=pointer2;
                              temp2=pointer2->next;
                              pervious=pointer2;
                              pointer2=temp2;  
                         
                    } 
                   // cout << pointer1->data << " " << pointer2->data << endl ;
                    if (pointer1->data<=pointer2->data){
                               smaller=pointer1;     
                    }
                    else{
                           smaller=pointer2;       
                    }
           }
            if (pointer1->data<=pointer2->data){
                       pervious->next=pointer1;
                       pointer1->next=pointer2;
                       last=pointer2;
            }
            else{
                       pervious->next=pointer2;
                       pointer2->next=pointer1; 
                       last=pointer1;
            }
           
}
template<typename T>
bool LinkedList<T>::is_loop(){
    if (last->next!=nullptr && last->next!=head){
           return true ;    
    }
    return false ;
}
template<typename T>
LinkedList<T>::~LinkedList()
{
     
    
}

