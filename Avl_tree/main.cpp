#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree *tree= new Tree(10);
   //  cout << tree->root->data << endl ; 
      
    tree->insert(30);
     cout << "I am here" << endl ;
    tree->insert(20);
      
    
    cout << tree->root->data << endl ; 
    cout << tree->root->left_child->data << endl;
    cout << tree->root->right_child->data << endl ;
     
     cout <<"Height left:  " << tree->root->cal_height_left() << endl ;
     cout << "Height right: " <<tree->root->cal_height_right() << endl ;
      
	return 0;
}
