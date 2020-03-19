#include <iostream>
#include "LinkedList.h"
#include "Queue.h"
using namespace std;

int main()
{
    int a[5]={10,20,30,40,50};
    LinkedList<int>list(5,a);
    list.display();
    Queue <int>q(list);
    q.enqueue(1000);
    q.display();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.enqueue(1200);
    q.display();
	return 0;
}
