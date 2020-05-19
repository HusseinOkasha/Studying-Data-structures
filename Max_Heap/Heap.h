/*
 * There are 2 types of heap max heap and min heap.
 * Max heap is a complete binary tree where every node is greater than all it descendants.
 * Min heap is a complete binary tree where every node is less than all it descendants.
 * Here I am implementing max heap.
 *
 * */

#ifndef MAX_HEAP_HEAP_H
#define MAX_HEAP_HEAP_H

#include <iostream>

using namespace std;

class Heap {
public:
    // attributes
    int* keys; // will carry all elements in the heap.
    int size; // would hold number of elements inside the heap.
    int capacity; // would hold maximum number of elements it can hold.
    // note: the capacity will increase when it is equal to the size.

    // methods
    Heap();
    void increase_capacity();
    void insert (int key);
    void heap_adapt(); // adapting heap after the insertion..
    void erase(); // note : deleting from max heap is only deleting the maximum (root) key.
    void print();
    ~Heap();



};


#endif //MAX_HEAP_HEAP_H
