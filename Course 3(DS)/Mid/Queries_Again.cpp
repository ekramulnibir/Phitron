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

    //cout<<"Value inserted after pos "<<pos<<endl;
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

    //cout<<val<<" inserted at head"<<endl;
}

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
        newNode->prev = tail;
        tail = newNode;
    }
}


void print(Node *head)
{
    cout<<"L -> ";
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void r_print(Node *tail)
{
    cout<<"R -> ";
    while(tail!=NULL)
    {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int sizeLL(Node *head)
{
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    cin>>n;

    while(n--)
    {
        int pos,val;
        cin>>pos>>val;

        if(pos>sizeLL(head))
        {
            cout<<"Invalid"<<endl;
        }
        else if(pos == 0)
        {
            insert_at_head(head,tail,val);
            print(head);
            r_print(tail);
        }

        else if(pos==sizeLL(head)){
            insert(head,tail,val);
            print(head);
            r_print(tail);
        }

        else {
            insert_at_pos(head, pos, val);
            print(head);
            r_print(tail);
        }

    }
    

    cout<<endl;
    return 0;
}