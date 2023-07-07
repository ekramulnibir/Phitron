#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert(Node *&head,Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node *head)
{
    while(head != NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void r_print(Node *tail)
{
    while(tail != NULL)
    {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }

    cout<<endl;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while(true)
    {

        cin>>val;

        if(val==-1) break;

        insert(head,tail,val);

    }

    print(head);
    r_print(tail);

    cout<<endl;
    return 0;
}