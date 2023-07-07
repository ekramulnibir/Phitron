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

void insert_at_pos(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);

    for(int i=0; i<pos-1; i++)
    {
        head = head->next; 
    }
    
    newNode->next = head->next;
    head->next = newNode;
    newNode->prev = head;
    newNode->next->prev = newNode;

    cout<<"Value inserted after pos "<<pos<<endl;
}

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }

    else{
        newNode -> next = head;
        head -> prev = newNode;
        head = newNode;
    }

    cout<<val<<" inserted at head"<<endl;
}

void insert_at_tail(Node *&head,Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if(tail == NULL)
    {
        insert_at_head(head,tail,val);
    }

    else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    cout<<val<<" inserted at tail"<<endl;
}

void delete_from_pos(Node *head, int pos)
{
    for(int i=0; i<pos-1; i++)
    {
        head = head->next;
    }
    Node *temp = head->next;
    head->next = head->next->next;
    head->next->prev = head; 

    cout<<temp->val<<" deleted"<<endl;

    delete temp;
    
}

void delete_tail(Node *&tail)
{
    Node *temp = tail;
    tail->prev->next = NULL;
    tail = tail->prev;

    cout<<temp->val<<" deleted from tail"<<endl;
    delete temp;
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

int LLsize(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    return count;
}


int main()
{
    /* Node *head = NULL;
    Node *tail = NULL;

    int ele;
    cout<<"Number of elements?";
    cin>>ele;

    for(int i=0; i<ele; i++)
    {
        int val; cin>>val;
        if(head == NULL) insert_at_head(head,tail,val);
        else insert_at_tail(head,tail,val);
    }

    print(head);
    r_print(tail); */


    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *tail = new Node(40);

    head->next = a;
    a->prev = head;
    a->next = b;
    b->prev = a;
    b->next = tail;
    tail->prev = b;

    print(head);
    r_print(tail);

    insert_at_pos(head,2,100);

    print(head);
    r_print(tail);
    

    insert_at_head(head,tail,-1);

    print(head);
    r_print(tail);

    insert_at_tail(head,tail,101);

    print(head);
    r_print(tail);

    
    cout<<"size of your LL - " <<LLsize(head)<<endl;

    cout<<endl; int pos;
    cout<<"Enter position to delete - "; cin>>pos;
    if(pos<LLsize(head))
    {
        delete_from_pos(head,pos);
    }
    else if(LLsize(head)==pos)
    {
        delete_tail(tail);
    }


    print(head);
    r_print(tail);

    cout<<endl;
    return 0;
}