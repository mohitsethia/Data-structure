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
node *build(int *a, int s, int e){ 
    if(s > e){ 
        return NULL;
    }   
    int mid = (s+e)/2;
    node *root = new node(a[mid]);
    root->left = build(a, s, mid-1);
    root->right = build(a, mid+1, e); 
    return root;
}
void replace(node *root){
    static int sum = 0;
    if(root == NULL){
        return;
    }   
    replace(root->right);
    sum += root->data;
    root->data = sum;
    replace(root->left);
}
void printpre(node *root){
    if(root == NULL){
        return;
    }   
    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
}
int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }   
    node *root = build(a, 0, n-1);
    replace(root);
    printpre(root);
    return 0;
}
