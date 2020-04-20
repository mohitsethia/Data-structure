#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *left;
        node *right;
        node(int d){ 
            data = d;
            left = NULL;
            right = NULL;
        }   
//        void recover(node *root, node **prev, node **first, node **mid, node **last){
//            if(root == NULL){
//                return;
//            }   
//            recover(root->left, first
//        }   
};
node *build(){
    int d;
    cin >> d;
    if(d == -1){
        return NULL;
    }   
    node *root = new node(d);
    root->left = build();
    root->right = build();
    return root;
}   
//int a[2];
void check(node *root, node **prev, node **first, node **mid, node **last){
    if(root == NULL){
        return;
    }   
//    static int x, y;
    check(root->left, prev, first, mid, last);
//    if(root->left != NULL){
//        if((root->data) < ((root->left)->data)){
//            a[0] = root->left->data;
//        }   
//    }   
//    if(root->right != NULL){
//        if(root->data >= ((root->right)->data)){
//            a[1] = root->data;
//        }   
//    }   
    if(*prev){
        if(*first == NULL && (*prev)->data >= root->data){
            *first = *prev;
            *mid = root;
        }   
        if(*first != NULL && (*prev)->data >= root->data){
            *last = root;
        }   
    }   
/*
    if(*prev && (*prev)->data > root->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
*/
    *prev = root;
    check(root->right, prev, first, mid, last);
}
void print(node *root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    print(root->left);
    print(root->right);
}
int main(){
    node *root = build();
    node *first = NULL;
    node *mid = NULL;
    node *last = NULL;
    node *prev = NULL;
    check(root, &prev, &first, &mid, &last);
//    cout << min(a[0], a[1]) << " " << max(a[0], a[1]);
//    cout << min(first->data, second->data) << " " << max(first->data, second->data);
    if(first && last){
        cout << min(first->data, last->data) << " " << max(first->data, last->data);
    }
    else{
        cout << min(first->data, mid->data) << " " << max(first->data, mid->data);
    }
    return 0;
}
