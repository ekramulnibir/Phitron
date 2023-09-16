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

vector<int> getReverse(Node* root){
    vector<int> v;
    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
        Node* node = q.front();
        q.pop();
        v.push_back(node->val);
        if(node->right) q.push(node->right);
        if(node->left) q.push(node->left);
    }
    reverse(v.begin(),v.end());
    return v;
}

int main()
{
    Node* root = binaryInput();
    
    vector<int> v = getReverse(root);
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    

    return 0;
}