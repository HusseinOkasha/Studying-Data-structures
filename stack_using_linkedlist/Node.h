#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template<typename T>
class Node
{
//private:
        
public:
     T data ;
       Node<T>*next; 
       Node(T data);
       Node(); 
       
          
      ~Node();
      

};
#include "Node.cpp"
#endif // NODE_H
