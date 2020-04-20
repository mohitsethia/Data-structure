#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node *build(string s)
{
    if (s == "true")
    {
        //10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

pair<int,bool> isHeightBalancedOptimised(node *root)
{
    // Write your code here
    pair<int, bool> p;
    if(root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    pair<int, bool> left = isHeightBalancedOptimised(root->left);
    pair<int, bool> right = isHeightBalancedOptimised(root->right);
    p.first = max(left.first, right.first) + 1;
    if(abs(left.first-right.first) <= 1 && left.second && right.second){
        p.second = true;
    }
    else{
        p.second = false;
    }
    return p;
}

int main()
{
    node *root = build("true");
    if(isHeightBalance(root).balance){
    cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}
