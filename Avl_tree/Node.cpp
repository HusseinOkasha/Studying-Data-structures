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
          if (left_child->right_child!=nullptr){
             height_left+=left_child->right_child->cal_height_left()+1;     
         }
         return height_left;
    }
    return 0;
    
}
int Node::cal_height_right(){
    if (right_child!=nullptr)
    {
         // fix bug here
          height_right=right_child->cal_height_right()+1;   
          if (right_child->left_child!=nullptr)
          {
               height_right+=right_child->left_child->cal_height_right()+1;     
          }
         return height_right;    
    }
     return 0;
}
int Node::get_left_height(){
       return height_left;   
}
int Node::get_right_height(){
       return height_right;     
}
Node::~Node()
{
}

    