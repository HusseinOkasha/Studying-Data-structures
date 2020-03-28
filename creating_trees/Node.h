#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
template <typename T>
class Node
{
private:

// attributes...
Node<T>*right_child;
Node<T>*left_child;
T data ;
          
public:
   // constructors.....
    Node ();
    Node(T data);
    Node(Node<T>*right_child, Node<T>*left_child , T data);
    
    // getters.....
    Node <T>* get_left_child();
    Node <T>* get_right_child();
    T get_data();
    
    //setters..
    void set_right_child(Node<T>*node);
    void set_left_child (Node<T>*node );
    void set_data(T data);
      
    // destructors....
    ~Node();

};
#include "Node.cpp"
#endif // NODE_H
