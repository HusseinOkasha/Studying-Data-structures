#include <iostream>
#include "Queue.h"
#include "Circular_Queue.h"
using namespace std;

int main()
{
    int arr[5]={10,20,30,40,50};
    Queue<int> q(arr,5);
   /* 
    q.enqueue(100);
    q.enqueue(120);
     
    cout << q << endl ;
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << q << endl ;
    /*cout << q << endl ;
    cout << *(q.get_end()) << endl ;
    */
    Circular_Queue<int> cq(arr,5) ;
    cout << cq << endl ;
    cq.dequeue();

   
    //cout << cq << endl ; 
    cq.enqueue(1000);
    cout << cq << endl ;
    cq.dequeue(); 
    cout << cq << endl ;
    cq.enqueue(1100);
    cout << cq << endl ;
    /*cout << "size: " << q1.get_size() << " capacity: " << q1.get_capacity() << endl ;
    cout  << "first: " <<*(q1.get_begin()) << " ::::::: " << "last: " <<*(q1.get_end()) << endl;  */
	return 0;
}