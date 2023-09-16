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

vector<int> getLevel(Node* root,int lvl)
{
    vector<int> v;

    if(!root) return v;

    queue<pair<Node*,int> > q;
    if(root) q.push(make_pair(root,0));

    

    while(!q.empty())
    {
        pair<Node*,int> pr = q.front();
        Node* node = pr.first;
        int level = pr.second;
        if(level == lvl)
        {
            v.push_back(node->val);
        }

        q.pop();


        if(node->left) q.push(make_pair(node->left,level+1));
        if(node->right) q.push(make_pair(node->right,level+1));

    }

    return v;
}

int main()
{
    Node* root = binaryInput();
    int level;
    cin>>level;
    
    vector<int> v = getLevel(root,level);

    if(!v.empty())
    {
        for(int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }

    }
    else cout<<"Invalid"<<endl;
    
    

    return 0;
}