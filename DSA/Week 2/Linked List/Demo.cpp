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

void insert_at_tail(Node *&head, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void inset_at_position(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;

    for(int i=0; i<pos-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void insert_at_head(Node *&head,int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void delete_from_position(Node *head, int pos)
{
    Node *temp = head;
    for(int i=0; i<pos-1; i++)
    {
        temp = temp -> next;
    }
    Node *delNode = temp->next;
    temp -> next = temp ->next ->next;
    delete delNode;
}

void delete_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;

    delete deleteNode;
    cout<<"Head deleted"<<endl;
}
void displayLL(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}



int main()
{
//     Node *head = new Node(10);
//     Node *a = new Node(20);
//     Node *b = new Node(30);
//     Node *c = new Node(40);
//     Node *d = new Node(50);

//    head->next = a;
//    a->next=b;
//    b->next=c;
//    c->next=d;

//    displayLL(head);

    Node *head = NULL;

    while(true)
    { 
        cout<<"Choose option-"<<endl;
        cout<<"1.Insert at tail"<<endl;
        cout<<"2.Display LinkList"<<endl;
        cout<<"3.Inset at any position"<<endl;
        cout<<"4.Inset at head"<<endl;
        cout<<"5.Delete from position"<<endl;
        cout<<"6.Delete head"<<endl;
        cout<<"7.Ext"<<endl;
        
        int opt;
        cin>>opt;

        if(opt == 1)
        {
            int val; 
            cout<<"Enter a value: "; cin>>val;
            insert_at_tail(head,val);
        }
        else if(opt == 2)
        {
            displayLL(head);
        }
        else if(opt == 3)
        {
            int pos,val;
            cout<<"Enter position: "; cin>>pos;
            cout<<"Enter value: "; cin>> val;

            if(pos==0)
            {
                insert_at_head(head,val);
            }
            else{
                inset_at_position(head,pos,val);
            }
        }
        else if(opt == 4) 
        {
            int val; cin>>val;
            insert_at_head(head,val);
        }

        else if(opt == 5)
        {
            int pos; 
            cout<<"Enter position: ";
            cin>>pos;
            if(pos == 0)
            {
                delete_head(head);
            }
            else{
                delete_from_position(head,pos);
            }
            
        }

        else if (opt == 6)
        {
            delete_head(head);
        }

        else if(opt == 7)
        {
            break;
        }
    }
}