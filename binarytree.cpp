include<iostream>
#include<queue>

using namespace std;

class node{
public:
    int data;
    node*right;
    node*left;
    node(int d){ 
        data = d;
        left = NULL;
        right = NULL;
    }   
};

node* buildtree(){
    int d;
    cin >> d;
    if(d == -1){
        return NULL;
    }   
    node* root = new node(d);
    root->left = buildtree();
    root->right = buildtree();
    return root;
}

void printpre(node* root){
    if(root == NULL){
        return;
    }   
    cout << root->data << " ";
    printpre(root->left);
    printpre(root->right);
}

void printin(node* root){
    if(root == NULL){
        return;
    }   
    printin(root->left);
    cout << root->data << " ";
    printin(root->right);
}

void printpost(node* root){
    if(root == NULL){
        return;
    }   
    printpost(root->left);
    printpost(root->right);
    cout << root->data << " ";
}

int height(node* root){
    if(root == NULL){
        return 0;
    }   
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls, rs) + 1;
}

void printkthlevel(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 1){
        cout << root->data << " ";
        return;
    }
    printkthlevel(root->left, k-1);
    printkthlevel(root->right, k-1);
}

void printallLevel(node* root){
    int h = height(root);
    for(int i = 1; i <= h; i++){
        printkthlevel(root, i);
        cout << endl;
    }
}

int count(node* root){
    if(root == NULL){
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

int Sum(node* root){
    if(root == NULL){
        return 0;
    }
    return root->data + Sum(root->left) + Sum(root->right);
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
//computing diameter in O(n^2) time;
int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    int op1 = h1 + h2;
    int op2 = diameter(root->left);
    int op3 = diameter(root->right);
    return max(op1, max(op2, op3));
}

void mirror(node*root){
    if(root == NULL){
        return;
    }
    swap(root->left, root->right);
    mirror(root->left);
    mirror(root->right);
    return;
}

class Pair{
    public:
        int height;
        int diameter;
};
//computing diameter in O(n)
Pair fastDiameter(node *root){
    Pair p;
    if(root == NULL){
        p.diameter = p.height = 0;
        return p;
    }
    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);
    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height+right.height, max(left.diameter, right.diameter));
    return p;
}

int replaceSum(node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int leftSum = replaceSum(root->left);
    int rightSum = replaceSum(root->right);
    int temp = root->data;
    root->data = leftSum+rightSum;
    return temp + root->data;
}
class HBPair{
    public:
        int height;
        bool balance;
};
HBPair isHeightBalance(node *root){
    HBPair p;
    if(root == NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }
    HBPair left = isHeightBalance(root->left);
    HBPair right = isHeightBalance(root->right);
    p.height = max(left.height, right.height)+1;
    if(abs(left.height-right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }
    return p;
}

node* createTreefromPREIN(int *in, int *pre, int s, int e){
    static int i = 0;
    if(s > e){
        return NULL;
    }
    node *root = new node(pre[i]);
    int index = -1;
    for(int j = s; j <= e; j++){
        if(in[j] == pre[i]){
            index = j;
            break;
        }
    }
    i++;
    root->left = createTreefromPREIN(in, pre, s, index -1);
    root->right = createTreefromPREIN(in, pre, index+1, e);
    return root;
}
int main(){
//    node* root = buildtree();
    int n;
    cout << "Enter the number of elements in the tree: ";
    cin >> n;
    int in[n], pre[n];
    cout << "Enter the elements of inorder traversal: ";
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    cout << "Enter the elements of preorder traversal: ";
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }
    node *root = createTreefromPREIN(in, pre, 0, n-1);
    cout << "Inorder " << endl;
    printin(root);
    cout << endl << "Preorder " << endl;
    cout << endl << "Postorder " << endl;
    printpost(root);
    cout << endl << "Height: ";
    cout << height(root);
    cout << endl << "Kth level : ";
    printkthlevel(root, 3);
    cout << endl << "All Levels " << endl;
    printallLevel(root);
    cout << "Count " << count(root);
    cout << endl;
    cout << "Sum " << Sum(root) << endl;
    cout << "BFS" << endl;
    bfs(root);
    cout << "Diameter: " << diameter(root) << endl;
    mirror(root);
    cout << "Mirror Image: " << endl;
    bfs(root);
    cout << endl;
    Pair p = fastDiameter(root);
    cout << "Height: " << p.height << endl;
    cout << "Diameter: " << p.diameter << endl;
    replaceSum(root);
    cout << "Tree After replacement by the sum of its child nodes: " << endl;
    bfs(root);
    cout << "Check if tree height balanced: ";
    if(isHeightBalance(root).balance){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
