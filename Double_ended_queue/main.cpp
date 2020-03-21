#include <iostream>
#include "Queue.h"
#include "DEqueue.h"
using namespace std;

int main()
{
  int arr [5]={10,20,30,40,50};  
  LinkedList<int>list(5,arr);  
  DEqueue<int>q(list);
  
  q.display();
  q.dequeue_back();
  q.display();
  q.dequeue();
  q.display();
  q.enqueue(1000);
  q.display();
	return 0;
}
