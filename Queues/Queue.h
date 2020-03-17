#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;
template<typename T>

class Queue
{
 private:
      T* first;// points to the first element in the queue
      T* last; // points to  just after the last element in the queue
      int size ;
      int capacity;  
 public:
  // constructors...          
     Queue(T element);
     Queue(T *elements, int size);
  // functions....
      void enqueue(T element );
      void dequeue();
      bool is_full();
      bool is_empty();
      void increase_capacity();
      int get_size();
      int get_capacity();
      T* get_begin();// returns pointer to first element in the queue.
      T* get_end();// return pointer to lindex just after last element in the queue.
      ostream&operator<<( ostream &out);
  // destructors...   
    ~Queue();

};
#include "Queue.cpp"
#endif // QUEUE_H
