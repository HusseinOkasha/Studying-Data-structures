#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node
{
    
public:
    //Attributes.......
    Node* right_child;
    int data;
    Node* left_child;
    int height_left=0;
    int height_right=0;
    
    //constructors.....
    Node();
    Node(int key);
    
   //functions.....
    int cal_height_left();
    int cal_height_right();
    int get_left_height(); 
    int get_right_height(); 
    //Destructors 
    ~Node();

};

#endif // NODE_H
