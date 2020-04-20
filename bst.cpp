#include<iostream>
#include<queue>
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
node* insertinbst(node *root, int data){
    if(root == NULL){
        return new node(data);
    }   
    if(data <= root->data){
        root->left = insertinbst(root->left, data);
    }   
    else{
        root->right = insertinbst(root->right, data);
    }   
    return root;
}

void bfs(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* f = q.front();
        if(f == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }   
        }   
        else{
            cout << f->data << " ";
            q.pop();
            if(f->left){
                q.push(f->left);
            }   
            if(f->right){
                q.push(f->right);
            }   
        }   
    }   
    return;
}

node* build(){
    int d;
    cin >> d;
    node*root = NULL;
    while(d != -1){
        root = insertinbst(root, d);
        cin >> d;
    }
    return root;
}
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
bool search(node *root, int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    if(data <= root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}
node *deleteinbst(node *root, int data){
    if(root == NULL){
        return NULL;
    }
    else if(data < root->data){
        root->left = deleteinbst(root->left, data);
        return root;
    }
    else if(data == root->data){
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }
        node *replace = root->right;
        while(replace->left != NULL){
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = deleteinbst(root->right, replace->data);
        return root;
    }
    else{
        root->right = deleteinbst(root->right, data);
        return root;
    }
}
int main(){
    node *root = build();
    cout << "Inorder Traversal" << endl;
    inorder(root);
    cout << endl;
    bfs(root);
    int a;
    cin >> a;
    if(search(root, a)){
        cout << "Present" << endl;
    }
    else{
        cout << "Not Present" << endl;
    }
    int d;
    cin >> d;
    deleteinbst(root, d);
    bfs(root);
    return 0;
}
