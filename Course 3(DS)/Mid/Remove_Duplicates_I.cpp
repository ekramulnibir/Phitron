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


void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void sortList(Node *head)
{
    Node *i;
    Node *j;

    for(auto i=head; i->next!=NULL; i=i->next)
    {
        for(auto j=i->next; j!=NULL; j=j->next)
        {
            if(i->val > j->val)
            {
                swap(i->val,j->val);
            }
        }
    }

}

void removeDuplicates(Node *head)
{
    while(head->next != NULL)
    {
        if(head->val == head->next->val)
        {
            head->next = head ->next->next;
        }
        if(head->next == NULL) break;

        else if(head->val != head->next->val)
        {
            head = head -> next;
        }
    }
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

    sortList(head);
    removeDuplicates(head);

    print(head);

    return 0;
}