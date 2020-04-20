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
};
node *insert(node *root, int data){
    if(root == NULL){
        return new node(data);
    }   
    if(data <= root->data){
        root->left = insert(root->left, data);
    }   
    else{
        root->right = insert(root->right, data);
    }   
    return root;
}

//node *build(int *a, int n){ 
//    node *root = NULL;
//    for(int i = 0; i < n; i++){
//        root = insert(root, a[i]);
//    }   
//    return root;
//}


node *deletedata(node *root, int data){
    if(root == NULL){
        return NULL;
    }   
    else if(data < root->data){
        root->left = deletedata(root->left, data);
        return root;
    }   
    else if(data == root->data){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }   
        else if(root->left != NULL && root->right == NULL){
            node *temp = root->left;
            delete root;
            return temp;
        }   
        else if(root->left == NULL && root->right != NULL){
            node *temp = root->right;
            delete root;
            return temp;
        }   
        node *replace = root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }    
        root->data = replace->data;
        root->right = deletedata(root->right, replace->data);
        return root;
    }
    else{
        root->right = deletedata(root->right, data);
        return root;
    }
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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int y;
		node *root = NULL;
//		  int a[n];
        for(int i = 0; i < n; i++){
            cin >> y;
//			  cin >> a[i];
			root= insert(root, y);
        }
//  	  root = build(a, n);
        int m;
        cin >> m;
        int x;
        for(int i = 0; i < m; i++){
            cin >> x;
            root = deletedata(root, x);
        }
        print(root);
		cout << endl;
    }
    return 0;
}
