#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int arr[5]={10,20,30,40,50};
    Queue<int> q(arr,5);
    q.enqueue(100);
    q.enqueue(120);
    cout << q << endl ;
     q.dequeue();
     cout << q << endl ;
     cout << *(q.get_end()) << endl ;
    /*cout << "size: " << q1.get_size() << " capacity: " << q1.get_capacity() << endl ;
    cout  << "first: " <<*(q1.get_begin()) << " ::::::: " << "last: " <<*(q1.get_end()) << endl;  */
	return 0;
}