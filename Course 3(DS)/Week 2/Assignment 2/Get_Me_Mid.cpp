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

void insert(Node *&head,int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if(head == NULL) {head = newNode; return;}
    

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void get_me_mid(Node *head,int count)
{
    Node *temp = head;
    if(count %2 != 0)
    {
        int res = 1;
        while(res < (count/2)+1)
        {
            temp = temp ->next;
            res++;
        }
        cout<<temp->val<<endl;
    }

    else{
        int res = 1;
        while(res < (count/2))
        {
            temp = temp ->next;
            res++;
        }
        cout<<temp->next->val<<" "<<temp->val<<endl;
    }

}

/* void displayLL(Node *head)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp = temp ->next;
    }
    cout<<endl;
} */

int main()
{
    Node *head = NULL;
    int val,count = 0;
    

    while(true)
    {
        cin>>val;
        if(val!=-1)
        {
            insert(head,val);
            count++;
        }
        else
        break;
    }

    /* 
    displayLL(head);
    cout<<endl; */

    for(Node *i = head; i->next != NULL; i=i->next)
    {
        for(Node *j = i->next; j!=NULL; j=j->next)
        {
            if(i->val>j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

    /*displayLL(head);
    cout<<endl; */

    get_me_mid(head,count);

    return 0;
}