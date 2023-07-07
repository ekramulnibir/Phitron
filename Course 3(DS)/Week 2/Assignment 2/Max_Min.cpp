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

void display(Node *head)
{
    int max = INT_MIN, min = INT_MAX;
    Node *temp = head;
    while(temp != NULL)
    {
        if(temp->val > max) max = temp->val;
        if(temp->val < min) min = temp->val;

        temp=temp->next;
    }

    cout<<max<<" "<<min;
}
int main()
{
    Node *head = NULL;
    int val;

    while(true)
    {
        cin>>val;
        if(val!=-1)
        {
            insert(head,val);
        }
        else
        break;
    }

    display(head);
    return 0;
}