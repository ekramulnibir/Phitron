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

void insert(Node *&head, Node *& tail, int val)
{
    Node *newNode = new Node(val);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node *head)
{
    while(head != NULL)
    {
        cout<<head->val<< " ";
        head = head->next;
    }

    cout<<endl;
}

void r_print(Node *tail)
{
    while(tail != NULL)
    {
        cout<<tail->val<< " ";
        tail = tail->prev;
    }

    cout<<endl;
}

void reverseList(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;

    while(i!=j && i->next!=j)
    {
         swap(i->val,j->val);
         i = i->next;
         j = j->prev;
    }
}

int is_plindrom(Node *head, Node *tail)
{
    Node *i = head;
    Node *j = tail;
    while(i!=j && i->prev != j)
    {
        if(i->val != j->val)
        return -1;
        
        i = i->next;
        j = j->prev;
    }
    return 1;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while(true)
    {
        cin>>val;
        if(val == -1) break;

        insert(head,tail,val);
    }

    print(head);
    r_print(tail);

    reverseList(head, tail);

    cout<<endl<<"palll: "<<is_plindrom(head,tail)<<endl;

    if(is_plindrom(head,tail)==-1) cout<<"NO\n";
    else cout<<"Yes\n";


    cout<<endl;
    return 0;
}