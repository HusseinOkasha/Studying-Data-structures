/*
 * time complexity : nlog(n)
 * n: for looping on all elements
 * log(n): as we continuously divide by 2
 * space comeplexity o(1)
 *
 * this algorithm is for large sized arrays .
 * */
#include <bits/stdc++.h>
using namespace std;
void shell_sort(int a[], int size){
    int gap = size/2 , i=0, k=0;
    for (;gap>0 ;gap/=2){
        i=0;
        for (int j=gap; j<size; j++){
            if (a[i] > a[j]){
                swap(a[i], a[j]);
            }
            k=i;
            while (k-gap>-1 && a[k-gap]> a[k]){
                swap(a[k], a[k-gap]);
                k=k-gap;
            }
            i++;
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
    int a[5]={-1,-2,-3,-4,-5};
    shell_sort(a,5);
    print(a,5);
    return 0 ;
}