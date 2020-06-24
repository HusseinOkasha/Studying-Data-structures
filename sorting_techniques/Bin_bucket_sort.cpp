
/*
 * time complexity O(N)
 * space complexity O(N) where n in the maximum element in the array
 * this is like count sort a space consuming algorithm.
 *
 * */

#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
           int value;
           Node* next;
           Node ():value(NULL),next(NULL){}
           Node (int value):value(value),next(NULL){}

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
bool erase(Node *count[], int a[10],int index  , int &k){
    Node * current = count[index];
    Node*  pre = NULL;
    if (count[index]==NULL){
        return false ;
    }
    while (current->next!= NULL){
        pre=current;
        current = current->next;
    }
    if (pre!=NULL){
        pre->next=NULL;
    }
    else {
        count[index]=NULL;
    }
    a[k]=current->value;
    k++;
    delete current;
    return true ;

}
void print(int * array , int size){
    for (int i=0; i<size ; i++){
        cout << array[i] << " ";
    }
    cout << endl ;
    cout << "================================" << endl;;

}
int main(){
    int a [10]={100,90,80,70,60,50,40,30,20,10};
    Node* count[100000]={NULL};
    for (int i=0; i< 10 ; i++){
       insert(count,a[i],a[i]);
    }
    int k=0;
    for (int i=0; i< 100000 ; i++){
        while (erase(count, a, i, k)){}

    }
    print(a,10);

    return 0;
}