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

Node* convert(int ar[],int n,int l,int r)
{
    if (l > r) return NULL;

    int mid = (l+r)/2;
    Node* root = new Node(ar[mid]);
    Node* leftNode = convert(ar,n,l,mid-1);
    Node* rightNode = convert(ar,n,mid+1,r);

    root->left = leftNode;
    root->right = rightNode;

    return root;
}

void levelOrder(Node* root)
{
    if(!root) return;

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<temp->val<<" ";

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        
    }
}

int main()
{
    int n;
    cin>>n;

    int ar[n];

    for(int i=0; i<n; i++) cin>>ar[i];

    Node* root = convert(ar,n,0,n-1);
    levelOrder(root);

    cout<<endl;
    return 0;
}