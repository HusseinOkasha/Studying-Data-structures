#ifndef CIRCULARDOUBLELINKEDLIST_H
#define CIRCULARDOUBLELINKEDLIST_H
#include <iostream>
#include <Node.h>
using namespace std;
template <typename T>
class CircularDoubleLInkedList
{
private:
// Attributes.......    
    Node<T>*head;
    Node<T>*last;
    int size ;       
public:
    //constructors........ 
    CircularDoubleLInkedList(int *elements , int numberOfELements);
    //Functions.....
      void display();
      Node<T>* begin();
      Node<T>* end();
      void insert(int index , T element);
      void erase(int index, int numberOfElements );
    //Destructors.....
    ~CircularDoubleLInkedList();

};
#include "CircularDoubleLInkedList.cpp"
#endif // CIRCULARDOUBLELINKEDLIST_H
