
/*
 * it has time complexty O(N).
 * space complexty O(N) where n is the maximum element in the array.
 *
 */
#include <bits/stdc++.h>
using namespace std;

void count_sort(int a [] , int size ){
    int counter [10001]={0};
    int k=0;
    for (int i=0 ;i< size ; i++){
        counter[a[i]]++;
    }

    for (int i=0; i<10001; i++){
        for(int j=0; j< counter[i] ;j++ ){
            a[k]=i;
            k++;
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
    int a [9]={50,50,40,65,65,1,1,0,0};
    count_sort(a,9);
    print(a,9);

    return 0;
}
