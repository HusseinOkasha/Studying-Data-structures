//
// Created by hussein on 6/26/20.
//

#include<bits/stdc++.h>
using namespace std;
/*

  deleting in linear probing is so expensive and requires a lot of work so we don't do it .
  let , n: number of elements in hash table , size: size of the hash table .
  n must be <= size/2 .
  ======================================================================================================================
  one of the drawbacks of linear probing is clustring (keys forming forming a group without empty cells between them.)
  why this is a drawback ..?
  As during searching you may be searching for 55 and the hash table from index 5 to index 9 looks like.
  5 25
  6 26
  7 27
  8 28
  9 29
  so you will have to search till the end.

 */

int Hash(int key){
    return key%10;
}
int prob (int a[] ,int key ){
    int index = Hash(key);
    int i=0;
    for (;a[(index+i)%10]!=0 ; i++){}
    return (index+i)%10;
}
void insert(int a[] , int key){
     int index= Hash(key);
     index=prob(a,index);
     a[index]=key;
}
int search (int a[] , int key){
    int index = Hash(key);
    int i=0;
    for (;a[(index+i)%10]!=key ; i++){
        if (a[(index+i)%10]==0){
            return -1;
        }
    }
    return (index+i)%10;
}

int main(){
    int a[10]={0};
    insert(a,1);
    insert(a,22);
    insert(a,23);
    insert(a,45);
    insert(a,26);
    insert(a,5);

    int search_result = search(a,50);
    cout << search_result << endl ;
    return 0;
}
