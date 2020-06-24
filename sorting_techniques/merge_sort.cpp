


/*
 * merge sort has Time complexty: nlogn , logn for merging &  n as we merge n times
 * space complexity: n + log(n) , n for extra array (during merging) , log(n): for the recursive calls
 *
 * */

#include <bits/stdc++.h>
using namespace std;


// mid : is the last element in the first list.
void merge (vector<int>&a , int l , int mid , int h){
    int i=l , j=mid+1 , k=l;
    vector<int>b(a.size(),0);
    while (i<=mid && j<=h){
        if (a[i] <=  a[j]){
            b[k]=a[i];
            k++;
            i++;
        }
        else if (a[i]>a[j]){
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while (i<=mid){
        b[k]=a[i];
        k++;
        i++;
    }
    while (j<=h){
        b[k]=a[j];
        k++;
        j++;
    }
    for (int i=l; i<=h;i++){
        a[i]=b[i];
    }

}
void print(const vector<int>&a , int size){
    for (int i=0; i<size ; i++){
        cout << a[i] << " ";
    }
    cout << endl ;
    cout << "================================" << endl;;

}
/*

// 1) iterative merge_sort:
// -------------------------
void merge_sort( vector<int>&a ,const int & size ){
    int l , mid , h;
    int i=0; // declared out side the loop in order to be able to check the below condition
    for ( i=2; i< size ; i*=2){
        for ( int j=0;  j+i-1 < size ; j+=i){
            l=j;
            h=j+i-1;
            mid=(l+h)/2;
            merge(a, l , mid , h);
        }
    }
    if (i/2<size){
        // this condation to detect when there odd number of sorted list where
        // we will merge first two but the third will not find one to be merged with so
        // we should merge the first two ones then merge it with them
        merge(a,0,i/2-1 ,size-1);
    }

}
========================================================================================================================
 */

// recursive merge_sort:
// -----------------------
void merge_sort(vector<int>&a , const int &size , int l, int h ){

   int mid ;
   if (l<h){
       mid=(l+h)/2;
       merge_sort(a,size , l ,mid);
       merge_sort(a,size , mid+1 , h);
       merge(a,l,mid ,h);
   }
}

int main(){
    vector<int >a={10,10,10,20,0,40};

    merge_sort(a,a.size(),0,a.size()-1);
    print(a,a.size());

    return 0;
}