

/*
 * space complexity O(n) n=9;
 * time complexity O(dN)=O(N) where d is the number of digits of the maximum number in the array
 *
 * */
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int value;
    Node* next;
    Node ():value(NULL),next(NULL){}
    Node(int value):value(value),next(NULL){}

};
void insert(Node* count[] , int index, int value ){
    Node * current=count[index];
    if (count[index]==NULL){
        count[index]= new Node(value);
    }
    else {
        while (current->next!=NULL){
            current=current->next;
        }
        current->next= new Node (value);
    }
}
bool erase(Node *count[], int a[],int index  , int &k){
    Node * current = count[index];
    if (current !=NULL){
        a[k]=current->value;
        count[index]=current->next;
        k++;
        return  true;
    }
    delete current;
return false;
}
int number_of_path(int a[], int size ){
    int max =INT32_MIN;
    int divide=10, counter=1;

    for (int i=0; i<size ; i++ ){
        if (a[i]> max){
            max=a[i];
        }
    }
    while (max/divide>0){
        counter++;
        divide*=10;
    }
    return counter;

}
void radix_sort(int a[] , int size){
   int divide=1 , number_of_paths=number_of_path(a,size);
   int a_index=0;
   Node* count[10]={NULL};
   for (int j=0; j<number_of_paths ;j++){
       a_index=0;
       for (int i=0; i<size ; i++){
           insert(count, (a[i]/divide)%10 , a[i]);
       }
       for (int i=0 ; i< 10 ;i++){
           while(erase(count, a, i , a_index )){}
       }
       divide*=10;
   }

}
void print(int * array , int size){
    for (int i=0; i<size ; i++){
        cout << array[i] << " ";
    }
    cout << endl ;
    cout << "================================" << endl;;

}
int main(){
    int a [5]={1,2,3,4,5};
    radix_sort(a,5);
    print(a,5);
    return 0;
}
