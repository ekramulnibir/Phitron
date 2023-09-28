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

int numberOfNodes(Node* root)
{
    int count = 0;

    if(!root) return count;

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        count++;
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

    return count;
}

int getMaxHeight(Node* root)
{
    if(!root) return 0;
    int l = getMaxHeight(root->left);
    int r = getMaxHeight(root->right);
    return max(l,r)+1;
}

int main()
{
    Node* root = binaryInput();
    if(pow(2,getMaxHeight(root))-1==numberOfNodes(root)) cout<<"YES";
    else cout<<"NO";

    cout<<endl;
    return 0;
}