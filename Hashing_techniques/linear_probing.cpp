//
// Created by hussein on 6/26/20.
//

#include<bits/stdc++.h>
using namespace std;
/*
 * deleting in linear probing is so expensive and requires alot of work so we don't do it .
 *
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
