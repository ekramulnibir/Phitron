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
    Node *temp = head;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void newInsert(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void reverseList(Node *&head, Node *tail)
{
    if(tail->next == NULL)
    {
        head = tail;
        return;
    }
    reverseList(head,tail->next);
    tail->next->next = tail;
    tail->next = NULL;
}

void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->val;
        head = head->next;
    }

    cout<<endl;
}

int is_palindrome(Node *head, Node *head1)
{
    while(head != NULL)
    {
        if(head->val!=head1->val)
        {return -1;}

        head = head->next;
        head1 = head1->next;
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
        if(val==-1)break;
        insert(head,tail,val);
    }

    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *temp = head;

    while(temp != NULL)
    {
        newInsert(head1,tail1,temp->val);
        temp = temp->next;
    }

    reverseList(head1,head1);

    if(is_palindrome(head,head1)==-1) cout<<"NO\n";
    else cout<<"YES\n";
   
   
    
    


    return 0;
}