//
// Created by hussein on 6/14/20.
//


/*
 * Adaptive algorithm:
 *
 * An adaptive algorithm is an algorithm that changes its behavior at the time it is run,
 * based on information available and on a priori defined reward mechanism (or criterion). ...
 * Another example is adaptive sort, whose behavior changes upon the presortedness of its input.
 *
 * */

 //=====================================================================================================================


/*
 * Stable algorithm:
 *
 * Stable sorting algorithms maintain the relative order of records with equal keys (i.e. values).
 * That is, a sorting algorithm is stable if whenever there are two records R and S with the same key
 * and with R appearing before S in the original list, R will appear before S in the sorted list.
 *
 * */

/*
 * Bubble sort has time complexty O(n^2)
 * Has a constant space complexty
 *
 * */


// bubble sort is stable and adaptive algorithm.

#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int* array  , int size){
    bool is_sorted=true;// it works as a flag to identify if the array is sorted.
    for(int i=0; i< size-1 ; i++){
        is_sorted=true;
        for (int j=0; j<size-1-i; j++){
             if (array[j] > array[j+1]){
                 swap(array[j], array[j+1]);
                 is_sorted=false;
             }
        }
        if (is_sorted== true){
            break;
        }
        // this condition will make time complexity O(n) if the array is already sorted.
    }
}
void print(int * array , int size){
    for (int i=0; i<size ; i++){
        cout << array[i] << " ";
    }
    cout << endl ;
    cout << "================================" << endl;;

}

int main() {
    int a[5]={10,20,30,40,50};
    bubble_sort(a,5);
    print(a,5);


    return 0;
}
