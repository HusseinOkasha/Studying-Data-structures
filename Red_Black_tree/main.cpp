
#include "Tree.h"
#include <bits/stdc++.h>

using namespace std;


int main() {
    Tree *t=  new Tree();
    vector<int>v={40,30, 20 ,10 ,9 , 8};
    for (int i=0; i<v.size();i++){
        t->insert(v[i]);
        t->visualize_tree();
    }
//    t->erase(10);
//    t->visualize_tree();
    t->erase(30);
    t->visualize_tree();
    t->clear();


    return 0;
}
