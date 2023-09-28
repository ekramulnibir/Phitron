#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

void insert(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void display_reverse(Node *temp)
{
    if(temp == NULL) return;

    display_reverse(temp->next);
    cout<<temp->val<<" ";

}

void display(Node *temp)
{
    if(temp == NULL) return;
    cout<<temp->val<<" ";
    display(temp->next);
    
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;

    while(true)
    {
        cin>>val;
        if(val!=-1)
        {
            insert(head,tail,val);
        }
        else
        break;
    }

    display_reverse(head);
    cout<<endl;
    display(head);
    return 0;
}