#include "priority_queue.h"
#include <iostream>
using namespace std;
template <typename T>
priority_queue<T>::priority_queue(T* elements , int* priorities, int size)
{
    high= new Queue<T>;
    medium=new Queue<T>;
    low = new Queue<T>;
     for (int i=0; i<size;i++){
           if (priorities[i]==1){
                    high->enqueue(*(elements+i));
           }
           else if (priorities[i]==2){
                     medium->enqueue(*(elements+i));   
            }
             else if(priorities[i]==3){
                      low->enqueue(*(elements+i));     
             }  
     }
}
/*====================================================================================================*/
template<typename T>
Queue<T>* priority_queue<T>::get_high(){
    return high;
}
/*====================================================================================================*/
template<typename T>
Queue<T>* priority_queue<T>::get_medium(){
    return medium;
}
/*====================================================================================================*/
template<typename T>
Queue<T>* priority_queue<T>::get_low(){
    return low;
}
/*====================================================================================================*/
template<typename T>
ostream &operator<<( ostream &out , priority_queue<T> &q){
           q.get_high()->display();
           q.get_medium()->display();
           q.get_low()->display();
}
/*====================================================================================================*/
template <typename T>
priority_queue<T>::~priority_queue()
{
}

