
/*
 * time complexity for search is load/2 + 1
 * load is max size per index
 * 1: for calculating the hash index (performing the hash function).
 *
 * */

#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
           int value ;
           Node * next;
           Node():value(0),next(NULL){}
           Node(int value):value(value), next(NULL){}

};
int my_hash(int x){
    return x%10;
}
void insert_sorted(int value , Node* a[] ,int  index){
    Node * current = a[index];
    Node * pre = NULL;
    Node * inserted= new Node (value);
    if (current!=NULL && value < a[index]->value){
        inserted->next=a[index];
        a[index]=inserted;
    }
    else{
        while (current!=NULL && value > current->value){
            pre=current;
            current = current->next;

        }
        inserted->next=current;
        if (pre!=NULL){
            pre->next=inserted;
        }
        else {
            a[index]=inserted;
        }

    }

}
void insert(int value , Node* a[] ){
    int index= my_hash(value);
    insert_sorted(value, a , index);
}

Node* search (int value , Node*a[]){
    int index = my_hash(value);
    Node * current = a[index];
    while (current!=NULL && current->value < value ){
        if (current->value==value){
            break ;
        }
        current=current->next;
    }
    if (current->value!= value){
        return NULL;
    }
    return current;
}
void erase (int value , Node* a[]){
    int index = my_hash(value);
    if (index<0){
        return ;
    }
    Node* current = a[index];
    Node* pre= NULL;
    while (current!=NULL && current->value < value ){
        if (current->value==value){
            break ;
        }
        pre=current;
        current=current->next;
    }
    if (current != NULL && current->value==value ){
        {
            if (pre==NULL){
                a[index]=current->next;
            }
            else {
                pre->next=current->next;
            }
            delete current;
        }
    }
}
int main(){
    Node*a [10]={NULL};
    int b [12]={10,20,40,50,75,45,12,13,14,17,64,0};
    for (int i=0; i<12 ;i++) {
        insert(b[i], a);
    }
    Node * search_result= search(30,a);
    erase(50,a);
    erase(10,a);
    erase(20,a);
    erase(40,a);
    erase(0,a);


    return 0;
}