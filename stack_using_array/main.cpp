#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
  int a [5]={10,20,30,40,50};  
  Stack<int> s(a,5);
  s.display();
  /*s.push(60);
  s.display();
  s.pop();
  s.display();
  */
Stack<int>s2(1);
s2.pop();
if (s2.is_empty()){
    cout << "it's empty" << endl ;    
} 
 if (s.is_full()==true){
     cout << "it is full" << endl ;
 }
 
 //cout << s.peek(5) << endl ; 
	return 0;
}
