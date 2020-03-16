#include <iostream>
#include "Node.h"
#include "LinkedList.h"
#include "CircularLinkedList.h"
using namespace std;

int main()
{
  /*  int arr[5]={-1,2,5,7,90};
    int a[5]={-6,5,20,22,24};
    LinkedList<int>first(5,arr);
    LinkedList<int>second(5,a);
  //  second.display();
    cout << "==================" << endl ;
    //first.display();
    first.merge(second);
    cout << " ============================= " << endl ;
  //  first.display();
    cout << "=======================" << endl;
   // first.reverse();
    //first.display();
    cout << "head : "<<first.begin()->data << endl ;
    cout << "Last: " << first.end()->data << endl ;
    cout << "=======================" << endl;
    //first.display();
   // first.insert_sorted(23);
    //
      int arr2[5]={10,20,30,40,50};
      LinkedList<int>third(5,arr2);
      first.append_list(third);
      first.display();
    //first.display();
     * ---------------------------------------------------
     * CIRCULAR LINKED LIST
     * 
     * */
     int a [5]={10,20,30,40,50};
     CircularLinkedList<int>B(5,a);
     B.reverse();
     B.display(); 
     B.erase(1,4);
     B.display();
     cout << " Head:" << B.begin()->data << endl ;
     cout << " Last:" << B.end()->next->next->data << endl;
	return 0;
}
