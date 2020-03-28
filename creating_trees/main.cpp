#include <iostream>
#include <queue>
#include "Node.h"
#include "BinaryTree.h"
using namespace std;

int main()
{
    /*
      Node<int>*p= new Node <int>(10);
    queue<Node<int>*>q;
    q.emplace(p);
    cout << q.front() << endl;
    */
   
      Node<int>n(10);
      BinaryTree<int>tree(n);
      tree.create_tree();
	return 0;
}
