//
// Created by hussein on 6/15/20.
//

#include <bits/stdc++.h>
using namespace std;
// i ====> looks for the first greater element ( from front to back ).
// j ====> looks for the first smaller element ( from back to front ).
void quick_sort(int * array , const int &size , int i , int j , int l , int  h ,  int pivot){
    if (l<h){
        if (j<i){
            swap(array[pivot],array[j]);
            pivot=j;
            quick_sort(array , size , l+1 , pivot , l , pivot , l);
            quick_sort(array , size , pivot+2 , h , pivot+1 , h , pivot+1 );
        }
        else {
            if (array[i]>=array[pivot] && array[j]<=array[pivot]){
                swap(array[i], array[j]);
                quick_sort(array,size,i+1, j-1,l,h,pivot );
            }
            else if (array[i]<array[pivot] && array[j] > array[pivot]){
                quick_sort(array,size,i+1, j-1,l,h,pivot );
            }
            else if (array[i]>=array[pivot] &&  array[j] > array[pivot] ){
                quick_sort(array,size,i, j-1,l,h,pivot );
            }
            else if (array[i]<array[pivot] &&  array[j]<=array[pivot] ){
                quick_sort(array,size,i+1, j,l,h,pivot );
            }
        }

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
    int array[5]={10,20,30,40,50};
    quick_sort(array, 5, 1 , 4,0,4,0);
    print(array,5);
    return 0 ;
}

