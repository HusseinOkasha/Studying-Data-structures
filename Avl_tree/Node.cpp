#include "Node.h"
#include <iostream>
using namespace std;
Node::Node()
{
    right_child=nullptr;
    left_child=nullptr;
    height_left=0;
    height_right=0;
    
}
Node::Node (int key)
{
     data = key ;
    
    right_child=nullptr;
    left_child=nullptr;
    
    height_left=0;
    height_right=0;
    
    
}
int Node::cal_height_left(){
    if (left_child!=nullptr){
          height_left=left_child->cal_height_left()+1;   
          return height_left;
    }
    else{
          return 0;    
    }
}
int Node::cal_height_right(){
    if (right_child!=nullptr){
          height_right=right_child->cal_height_right()+1;   
          return height_right;
    }
    else{
          return 0;    
    }
}
Node::~Node()
{
}

    