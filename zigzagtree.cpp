#include<iostream>
#include<algorithm>
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

node *buildtree(string s){
    if(s == "true"){
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if(l == "true"){
            root->left = buildtree(l);
        }   
        string r;
        cin >> r;
        if(r == "true"){
            root->right = buildtree(r);
        }   
        return root;
    }   
    return NULL;
}

int height(node *root){
    if(root == NULL){
        return 0;
    }   
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printoddKthlevel(node *root, int k){ 
    if(root == NULL){
        return;
    }   
    if(k == 1){ 
        cout << root->data << " ";
        return;
    }   
    printoddKthlevel(root->left, k-1);
    printoddKthlevel(root->right, k-1);
}

void printevenKthlevel(node *root, int k){ 
    if(root == NULL){
        return;
    }   

    if(k == 1){
        cout << root->data << " ";
        return;
    }
    printevenKthlevel(root->right, k-1);
    printevenKthlevel(root->left, k-1);
}

void printallLevel(node *root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        if(i % 2 == 0){
            printevenKthlevel(root, i);
        }
        else{
            printoddKthlevel(root, i);
        }
    }
}

int main(){
    node *root = buildtree("true");
    printallLevel(root);
    return 0;
}
