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

void insert_at_head(Node *&head,int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insert_at_tail(Node *&head,Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void display(Node *head,Node *tail)
{
    cout<<head->val<<" "<<tail->val<<endl;

}

/* void displayLL(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head ->next;
    }

    cout<<endl;
} */
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int n;
    cin>>n;

    int a,b; cin>>a>>b;
    insert_at_tail(head,tail,b);
    display(head,tail);
    n--;

    while(n--)
    {
        int x, y;
        cin>>x>>y;

        if(x==0) 
        {
            insert_at_head(head,y);
            display(head,tail);
        }
        else{
            insert_at_tail(head,tail,y);
            display(head,tail);
        }
    }

    /* cout<<"final list: ";
    displayLL(head); */
    

   
    return 0;
}