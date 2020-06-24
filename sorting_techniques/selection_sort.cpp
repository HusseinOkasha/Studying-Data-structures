//
// Created by hussein on 6/15/20.
//

#include <bits/stdc++.h>
using namespace std;

/*
 * selection_sort time complexity O(n^2)
 * selection sort is not adapted nor stable.
 *
 * */


void selection_sort(int *array , int size ){
    for(int i=0; i<size ;i++){
        int k =i;
        for (int j=i+1; j<size; j++){
            if (array[j] < array[k]){
                k=j;
            }
        }
        swap (array[i],array[k]);
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
    int array[5]={5,8,7,3,2};
    selection_sort(array,5);
    print(array,5);

    return 0;
}