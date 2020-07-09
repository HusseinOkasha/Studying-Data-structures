//
// Created by hussein on 7/9/20.
//



#include <bits/stdc++.h>
using namespace std;
void union_ (int a , int b , int set[]){

    if(set[a] < set[b]){
        set[b]+=set[a];
        set[a]=b;
    }
    else {
        set[a]+=set[b];
        set[b]=a;
    }
}
int  find_(int a , int set[]){
    while (set[a] >0 ){
        a=set[a];
    }
    return a;
}
int main(){
    /*
        1st & 2nd rows represents the terminals of the edge.
        3rd row represents the cost of the the edge.
        note: 9 is because we have 9 edges ...
     */
    int edges[9][3]={{1,2,28},{1,6,10},{2,3,16},{2,7,14},{3,4,12},
                    {4,5,22},{4,7,18},{5,6,25},{5,7,24}};
    int set[8]={-1,-1,-1,-1,-1,-1,-1,-1};// as we have 7 nodes & we use it to detect cycles.
    int included[9]={0};// this array is to mark the included edges.
    int tree[2][6];
    int min= INT32_MAX , index ;
    /*
       6: because we have 7 nodes.
       2: represents the terminals of the edges.
       note : tree will be the answer
    */
    for (int i=0; i< 6 ;){
        min= INT32_MAX;
        for (int j=0; j<9 ;j++ ){
            if (included[j]==0 && min > edges[j][2]){
                min=edges[j][2];
                index=j;
            }
        }
        if (find_(edges[index][0], set ) !=  find_(edges[index][1], set ) ){
            union_(edges[index][0] ,edges[index][1] , set );
            tree[0][i]=edges[index][0];
            tree[1][i]=edges[index][1];
            included[index]=1;
            i++;
        }
        else {
            included[index]=1;

        }


    }
    for (int i=0; i< 6 ;i++){
        cout << tree[0][i] << " " << tree[1][i] << endl;
    }


    return 0;
}