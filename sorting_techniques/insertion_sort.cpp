
/*
 *
 * insertion sort is adaptive and stable algorithm.
 * time complexity O(n^2).
 *
 * */
using namespace std ;
#include <bits/stdc++.h>

void insertion_sort(int* array, int size ){
    bool check = false ;
    for (int i=1; i<size ;i++){
         int x = array[i];
         check=false;
         for (int j=i-1; j>=0 ; j--){
             if (array[j]>x){
                 array[j+1]=array[j];
             }
             else {
                  check =true;
                  array[j+1]=x;
                  break;
             }
         }
         if (check == false ){
             array[0]=x;
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

    int array[5]={8,5,7,3,2};
    insertion_sort(array, 5);
    print(array , 5);
    return 0;
}
