#include <iostream>
#include "Queue.h"
using namespace std;

int main()
{
    int arr[5]={10,20,30,40,50};
    Queue<int> q1(arr,5);
    cout << q1 << endl ;
    
	return 0;
}