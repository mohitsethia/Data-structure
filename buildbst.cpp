#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int d){ 
        data = d;
        left = NULL;
        right = NULL;
    }   
};
node *build(int *arr, int s, int e){ 
    if(s > e){ 
        return NULL;
    }   
    int mid = (s+e)/2;
    node *a = new node(arr[mid]);
    a->left = build(arr, s, mid-1);
    a->right = build(arr, mid+1, e); 
    return a;
}
void preorder(node *root){
    if(root == NULL){
        return;
    }   
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int t;
    cin >>t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }   
        node *root = build(arr, 0, n-1);
        preorder(root);
    }   
}
