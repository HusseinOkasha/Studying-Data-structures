#include <iostream>
#include "priority_queue.h"
using namespace std;

int main()
{
    int arr[5]={10,20,30,40,50};
    int priorities[5]={1,1,3,3,2};
    priority_queue<int>p(arr,priorities,5);
  
    cout << p << endl ;
	return 0;
}
