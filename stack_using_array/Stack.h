#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template<typename T>

class Stack
{
private:
   //attributes..
   T* container;// array for storing elements.. 
   T* top;// pointer to the last element entered the stack..
   int size;// number of elements inside the stack...
   int capacity;// number of elements stack can store..
public:
    // constructors.....
    Stack(T element );
    Stack(T* elements , int size);
    
    //functions...
    T get_top();// it returns last element in the stack..
     void display();   
     void push (T element);
     void increase_capacity();   
     void pop();// it removes the top element in the stack..
     T peek(int index);// element at cetain index
     bool is_full();
     bool is_empty();
    // destructors...
    ~Stack();

};
#include "Stack.cpp"
#endif // STACK_H
