#include <iostream>
#include "DoubleLinkedList.h"
#include "CircularDoubleLInkedList.h"
using namespace std;
int main()
{
  int a [5]={10,20,30,40,50};  
  DoubleLinkedList<int>B(a,5);
  /*B.display();
  B.push_back(200);
  B.display();
  cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
  B.push_front(900);
  B.display();
  cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
  */
   /*B.display();
   B.insert(2,70);
   B.display();
   cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
   */
   /*B.display();
   B.pop_back();
   B.display();
   cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
   B.pop_front();
   B.display();
   cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
   */
 /*  B.display();
   B.erase(0,4);
   B.display();
   cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
    */
    /*B.reverse();
    B.display();
    cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
    B.reverse();
    B.display();
    cout << "Head: " << B.begin()->data << " Last: " << B.end()->data << endl ;  
    */
    // Circular double linked list.....
     CircularDoubleLInkedList<int>B2(a,5);
    /* B2.display();
     cout << B2.begin()->pervious->data << endl;
     cout << B2.end()->next->data<< endl;*/
     /*B2.insert(6,70);
     B2.display();
     cout << B2.begin()->pervious->data << endl;
     cout << B2.end()->next->data<< endl;
     */
     B2.erase(2,1);
      B2.display();
     cout << B2.begin()->pervious->data << endl;
     cout << B2.end()->next->data<< endl;
	return 0;
}
