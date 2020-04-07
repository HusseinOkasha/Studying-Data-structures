#include "Tree.h"
#include <iostream>
using namespace std;

int main()
{
    Tree* tree = new Tree(50);
    //  cout << tree->root->data << endl ;

    
    cout << "I am here" << endl;
    tree->insert(10);
    tree->insert(20);
    tree->insert(30);
    tree->insert(60);
    tree->insert(70);
    tree->insert(80);
    
    //tree->delete_key(80);
    //tree->delete_key(70);
    cout << "==============================================================" << endl ;
    
    cout << "Root: " << tree->root->data << endl;
    cout << "Left: " << tree->root->left_child->data << endl;
    cout << "Right: " << tree->root->right_child->data << endl;
    cout << "==============================================================" << endl ;
      
    cout << "Height left:  " << tree->root->cal_height_left(tree->root) << endl;
    cout << "Height right: " << tree->root->cal_height_right(tree->root) << endl;
    
    return 0;
}
