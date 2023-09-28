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

int count_leaf(Node * root)
{
    if(root==NULL) return 0;
    
    if(root->left == NULL && root->right == NULL)
    {
        return 1; 
    }
    else{
        int left = count_leaf(root->left);
        int right = count_leaf(root->right);

        return left + right;
    }
}


int main()
{
    Node* root = binaryInput();
    cout<<count_leaf(root);
    

    cout<<endl;
    return 0;
}