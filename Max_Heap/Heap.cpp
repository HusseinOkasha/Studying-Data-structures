//
// Created by hussein on 5/19/20.
//

#include "Heap.h"
#include <iostream>

using namespace std;
Heap::Heap()
:capacity(10) , size(0){
   keys = new int [10];
}
void Heap::increase_capacity(){
    int* temp = keys;
    keys = nullptr ;
    keys = new int [size*2];
    for (int i=0; i< size ;i++){
        keys[i]= temp[i];
    }
    delete [] temp;
    capacity = size*2;
}
void Heap::insert(int key) {
    if (capacity==size){
        increase_capacity();
    }
    keys[size]= key;
    size++;
    heap_adapt();


}
void Heap::heap_adapt() {
    int index= size-1;
    int parent= (size/2)-1;
    while (keys[index]>keys[parent] && index>-1 && parent>-1){
        swap(keys[index], keys[parent]);
        index=parent;
        parent=(index+1)/2-1;
    }

}
void Heap::print() {
    for (int i=0; i<size;i++){
        cout << keys[i] << endl ;
    }
}
void Heap::erase() {
    keys[0]=keys[size-1];
    size--;
    int parent=0;
    int left_child = 2*(parent+1)-1;
    int right_child = 2*(parent+1);

    while(parent < size && left_child <size && right_child < size){
          if ( keys[left_child] > keys[parent]){
              swap(keys[left_child],keys[parent]);
              parent = left_child;
          }
          else if (keys[right_child] > keys[parent]){
              swap(keys[right_child] , keys[parent]);
              parent= right_child;
          }
          else {
              break;
          }
          left_child = 2*(parent+1)-1;
          right_child = 2*(parent+1);
    }

}
Heap::~Heap() {
    delete [] keys;
}
