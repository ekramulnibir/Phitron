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
    if(val==-1) root=NULL;
    else root = new Node(val);

    queue<Node*> q;
    if(root) q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        int l,r;
        cin>>l>>r;

        Node *left;
        Node *right;

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

bool search(Node* root, int x)
{
    if(!root) return false;
    if(root->val == x) return true;

    if(x<root->val)
    {
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}

void insert(Node* &root,int x)
{
    if(!root) {
        root = new Node(x);
        return;
    }

    if(x<root->val){
        if(!root->left) root->left = new Node(x);

        else insert(root->left,x);
    }

    else{
        if(!root->right) root->right = new Node(x);

        else insert(root->right,x);
    }
}

int main()
{
    Node* root = binaryInput();
    levelOrder(root);

    int searchValue; cin>>searchValue;

    if(search(root,searchValue)) cout<<"YES\n";
    else cout<<"NO\n";


    int insertVale; cin>>insertVale;

    insert(root,insertVale);
    levelOrder(root);

    cout<<endl;
    return 0;
}