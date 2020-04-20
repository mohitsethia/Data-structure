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

node *buildtree(node *root, int data){
    if(root == NULL){
        return new node(data);
    }   
    if(data <= root->data){
        root->left = buildtree(root->left, data);
    }   
    else{
        root->right = buildtree(root->right, data);
    }   
    return root;
}

void preorder(node *root){
    if(root == NULL){
        return;
    }   
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root, int k, int l){ 
    if(root == NULL){
        return;
    }   
    inorder(root->left, k, l); 
    if(root->data >= k && root->data <= l){ 
        cout << root->data << " ";
    }   
    inorder(root->right, k, l); 
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        node *root = NULL;
        for(int i = 0; i < n; i++){
            int data;
            cin >> data;
            root = buildtree(root, data);
        }
        int k, l;
        cin >> k >> l;
        cout << "# Preorder : ";
        preorder(root);
        cout << endl;
        cout << "# Nodes within range are : ";
        inorder(root, k, l);
    }
    return 0;
}
