//
// Created by hussein on 12/23/20.
//

#include "Tree.h"
#include <bits/stdc++.h>

using namespace std;

Tree::Tree()
        :root(NULL){

}
Tree::Tree(Node* root)
        :root(root){

}

void Tree::insert(int key ){
    Node* inserted= new Node(key);
    Node* current=root, *parent=nullptr;
    while (current!=nullptr){
        if (key < current->val){
            parent=current;
            current= current->l_child;
        }
        else if (key >= current->val){
            parent= current;
            current=current->r_child;
        }
    }
    if (parent==nullptr){
        root= inserted;
        root->red=false;
    }
    else {
        if (key < parent->val){
            parent->l_child=inserted;
        }
        else if (key >=parent->val){
            parent->r_child=inserted;
        }
        inserted->parent=parent;
        adapt_tree(parent, inserted);
    }

}
vector<vector<Node*>> Tree::level_order() {
    queue<Node*>q;
    vector<vector<Node*>> levels;
    int size;
    bool check=true;
    Node* current=root;
    q.push(root);
    vector<Node*>level;
    while (!q.empty()){
        size=q.size();
        check=false;
        for (int i=0; i< size;i++){
            current =q.front();
            level.push_back(current);
            if (current!=NULL){
                q.push(current->l_child);
                q.push(current->r_child);
                check=true;
            }
            else{
                q.push(nullptr);
            }
            q.pop();
        }
        levels.push_back(level);
        level.clear();
        if(!check){break;}
    }
    return levels;

}
void Tree::visualize_tree() {
    vector<vector<Node*>>levels=level_order();
    int tab_factor=levels.size(), tab_factor_inner=levels.size();
    for (int i=0; i<levels.size();i++,tab_factor-- ){
        for (int k=0; k<tab_factor;k++){cout << "\t";}
        for (int j=0;j< levels[i].size();j++){

            if (levels[i][j]!=NULL){
                cout << levels[i][j]->val ;
                if (levels[i][j]->red){cout << " R\t";}
                else{cout << " B\t";}
            }
            else{
                cout << "\t  ";
            }
            //for(int k=0;k<tab_factor-1;k++){cout << "\t";}

        }
        cout << endl ;
    }
    cout << "==================================" << endl ;
}

void Tree::rr_rotation(Node* root) {
//    root->red=true;
//    root->r_child->red=false;

    Node* temp1 =root->r_child->l_child;
    Node* temp2=root->r_child;
    root->r_child->l_child=root;
    root->r_child=temp1;
    temp2->parent=root->parent;
    if(root->parent!=NULL){
        if (is_left_child(root)){
            root->parent->l_child=temp2;
        }
        else{
            root->parent->r_child=temp2;
        }
    }
    root->parent=temp2->parent;

    if (root==this->root){
        this->root=temp2;
    }
}

void Tree::rl_rotation(Node *root) {
    Node* parent= root->r_child;
    Node* child= root->r_child->l_child;
//      child->red=false;
//      root->red=true;
    Node* temp1= child->l_child;
    Node* temp2= child->r_child;
    child->r_child=parent;
    child->l_child=root;
    root->r_child=temp1;
    parent->l_child=temp2;
    child->parent =root->parent;
    if (root->parent!=nullptr){
        if (is_left_child(root)){
            root->parent->l_child=child;
        }
        else{
            root->parent->r_child=child;
        }
    }

    root->parent=child;
    parent->parent=child;
    if (root==this->root){
        this->root=child;
    }
}
void Tree::ll_rotation(Node* root){


    Node* temp1= root->l_child->r_child;
    Node* temp2= root->l_child;
    root->l_child->r_child=root;
    root->l_child=temp1;
    temp2->parent=root->parent;
    if (root->parent!=nullptr){
        if (is_left_child(root)){
            root->parent->l_child=temp2;
        }
        else{
            root->parent->r_child=temp2;
        }
    }
    root->parent= temp2;
    if (root==this->root){
        this->root=temp2;
    }


}
void Tree::lr_rotation(Node*root){
    Node* child= root->l_child->r_child;
    Node* parent= root->l_child;
//    root->red=true;
//    child->red=false;
    Node* temp1=child->l_child;
    Node* temp2=child->r_child;
    child->r_child=root;
    parent->r_child=temp1;
    root->l_child=temp2;
    child->parent=root->parent;
    if (root->parent!=nullptr){
        if (is_left_child(root)){
            root->parent->l_child=child;
        }
        else{
            root->parent->r_child=child;
        }
    }
    root->parent=child;
    parent->parent=child;
    if (root==this->root){
        this->root=child;
    }

}
void Tree::adapt_tree(Node *parent ,Node*child) {
    Node* uncle;
    if (parent==nullptr || !parent->red){
        return;
    }
    while ( child!=nullptr && child->red && parent->red ) {
        uncle =get_uncle(child);
        if( uncle==nullptr || !uncle->red ){
            if (is_left_child(child) && is_left_child(parent)){
                child->parent->parent->red=true;
                child->parent->parent->l_child->red=false;
                ll_rotation(child->parent->parent);
                child=child->parent;
            }
            else if (!is_left_child(child) && is_left_child(parent)){
                child->parent->parent->red=true;
                child->red=false;
                lr_rotation(child->parent->parent);

            }
            else if (!is_left_child(child) && !is_left_child(parent)){
                child->parent->parent->red=true;
                child->parent->parent->r_child->red=false;
                rr_rotation(child->parent->parent);
                child=child->parent;
            }
            else if (is_left_child(child) && !is_left_child(parent)){
                child->red=false;
                child->parent->parent->red=true;
                rl_rotation(child->parent->parent);
            }
        }
        else{
            recolor(child->parent->parent);
        }
    }
}
Node* Tree::get_uncle(Node* child){
    Node* parent= child->parent;
    Node* grand_parent;
    if (parent==nullptr){
        return nullptr;
    }
    else{
        grand_parent=parent->parent;
    }
    if (parent == grand_parent->l_child){
        return grand_parent->r_child;
    }
    else if (parent == grand_parent->r_child){
        return grand_parent->l_child;
    }
}

bool Tree::is_left_child(Node* child){
    Node* parent= child->parent;
    if (parent->l_child==child){
        return true;
    }
    return false;
}
void Tree::recolor(Node* root){
    root->red=true;
    if (root==this->root){ root->red=false;}
    root->r_child->red=false;
    root->l_child->red=false;
}
Node* Tree::search(int key){
    Node* current=this->root;
    while(current!=nullptr && current->val!=key){
        if (key < current->val){
            current= current->l_child;
        }
        else if (key > current->val){
            current=current->r_child;
        }
    }
    return current ;
}

Node* Tree::erase(int key){
    Node* to_be_erased= search(key);
    if (to_be_erased==nullptr){
        return nullptr;
    }
    if(to_be_erased->red){
        return erase_red_node(to_be_erased);
    }
    else{
        return erase_black_node(to_be_erased);
    }

}

Node* Tree::get_predecessor(Node* root){
    Node* current= root->l_child;
    if (current==nullptr){
        return nullptr;
    }
    else{
        while (current->r_child!=nullptr){
            current=current->r_child;
        }
    }
    return current;
}
Node* Tree::get_successor(Node* root){
    Node* current= root->r_child;
    if (current==nullptr){
        return nullptr;
    }
    else{
        while (current->l_child!=nullptr){
            current=current->l_child;
        }
    }
    return current;
}
bool Tree::is_leaf_node(Node *root) {
    return root == nullptr || (root->l_child == nullptr && root->r_child == nullptr);
}
Node* Tree::erase_red_node(Node *to_be_erased) {
    Node * predecessor= get_predecessor(to_be_erased);
    Node * successor= get_successor(to_be_erased);
    Node* current= to_be_erased;
    if (is_leaf_node(to_be_erased)){
        if(is_left_child(to_be_erased)){
            to_be_erased->parent->l_child=nullptr;
        }
        else{
            to_be_erased->parent->r_child=nullptr;
        }
    }
    else{
        while(current->l_child!=nullptr || current->r_child!=nullptr){
            predecessor= get_predecessor(current);
            successor= get_successor(current);
            if (predecessor!=nullptr && successor!=nullptr){
                if (rand()%2==0){
                    current=predecessor;
                }
                else{
                    current=successor;
                }
            }
            else if (predecessor!=nullptr){
                current=predecessor;
            }
            else if (successor!= nullptr){
                current=successor;
            }
        }
        to_be_erased->val=current->val;
    }
    if (is_left_child(current)){
        current->parent->l_child=nullptr;
    }
    else{
        current->parent->r_child=nullptr;
    }
    return current;
}
Node* Tree::erase_black_node(Node *to_be_erased) {
    Node* parent= to_be_erased->parent;
    Node* replacement_node;
//    if (is_left_child(to_be_erased)){
//        replacement_node=parent->r_child;
//    }
//    else{
//        replacement_node=parent->l_child;
//    }
    replacement_node=erase_red_node(to_be_erased);
    adapt_after_deletion(replacement_node->parent,replacement_node);

}
void Tree::adapt_after_deletion(Node * parent , Node* replacement_node) {
    Node* brother;


    brother= get_brother(replacement_node,parent);


    if (brother!=nullptr && brother->red ){
        // Deletion is done on the left subtree..
        if(replacement_node->val < replacement_node->parent->val ){
            rr_rotation(parent);
        }
        else {
            ll_rotation(parent);
        }
    }
    else if((brother!=nullptr && !brother->red ) && (brother->l_child==nullptr || !brother->l_child->red) &&
            (brother->r_child==nullptr || !brother->r_child->red)){
        brother->red=!brother->red;
        parent->red=!parent->red;
    }
    else if ((brother!=nullptr && !brother->red ) && (brother->l_child!=nullptr || brother->l_child->red) ||
             (brother->r_child!=nullptr || brother->r_child->red)){
        if (brother->r_child!=nullptr && brother->r_child->red){
            if (brother->val < parent->val){
                lr_rotation(parent);
            }
            else{
                rr_rotation(parent);
            }
        }
        else if (brother->l_child!=nullptr && brother->l_child->red){
            if (brother->val < parent->val){
                ll_rotation(parent);
            }
            else{
                rl_rotation(parent);
            }
        }

    }

}
Node* Tree::get_brother(Node* child, Node* parent){
    if (this->root== child){
        return nullptr;
    }
    else{
        if (parent->l_child==child){
            return parent->r_child;
        }
        else{
            return parent->l_child;
        }
    }
    return nullptr;
}
void Tree::clear() {
    Node* temp= root;
    root=nullptr;
    delete temp;
}
Tree::~Tree(){
    delete root;
}