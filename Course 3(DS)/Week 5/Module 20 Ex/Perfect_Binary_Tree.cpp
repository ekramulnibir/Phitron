#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};

Node* binaryInput()
{
    int val;
    cin>>val;

    Node* root;
    if(val==-1) root = NULL;
    else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;     

        Node* left;
        Node* right;

        if(l==-1) left=NULL;
        else left = new Node(l);

        if(r==-1) right=NULL;
        else right = new Node(r);

        temp->left = left;
        temp->right = right;


        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return root;
}

bool isPerfectBinaryTree(Node* root)
{
    if(!root->left && !root->right) return true;
    if(!root->left || !root->right) return false;
    bool l = isPerfectBinaryTree(root->left);
    bool r = isPerfectBinaryTree(root->right);
    if(l==false || r==false) return false;

    return true;

}



int main()
{
    Node* root = binaryInput();
    if(isPerfectBinaryTree(root)) cout<<"YES";
    else cout<<"NO";
    
    return 0;
}