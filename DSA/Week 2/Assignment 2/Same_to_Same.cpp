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

int check_same(Node *head1,Node *head2, int L1, int L2)
{
    if(L2!=L1) return -1;

    else{
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->val != head2->val) return -1;

            head1 = head1->next;
            head2 = head2->next;
        }
    }

    return 1;
}

void insertLL1(Node *&head,int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if(head == NULL) {head = newNode; return;}
    

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertLL2(Node *&head,int val)
{
    Node *newNode = new Node(val);
    Node *temp = head;
    if(head == NULL) {head = newNode; return;}
    

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp->val<<" ";
        temp = temp ->next;
    }
}
int main()
{
    Node *head1 = NULL;
    Node *head2 = NULL;
    int L1 = 0, L2 = 0;
    int val;

    while(true)
    {
        cin>>val;
        if(val!=-1)
        {
            insertLL1(head1,val);
            L1++;
        }
        else
        break;
    }

    while(true)
    {
        cin>>val;
        if(val!=-1)
        {
            insertLL2(head2,val);
            L2++;
        }
        else break;
    }

    if(check_same(head1,head2,L1,L2)==-1) cout<<"NO\n";
    else cout<<"YES\n";
    
    return 0;
}