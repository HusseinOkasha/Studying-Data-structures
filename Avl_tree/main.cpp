#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
	Tree *tree= new Tree(30);
   //  cout << tree->root->data << endl ; 
    
    tree->insert(20);
     cout << "I am here" << endl ;
    tree->insert(10);
    cout << tree->root->data << endl ; 
    cout << tree->root->left_child->data << endl;
    cout << tree->root->right_child->data << endl ;
	return 0;
}
