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

class myQueue
{
    public:
        Node *head = NULL;
        Node *tail = NULL;
        int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNoode = new Node(val);
        if(head == NULL)
        {
            head= newNoode;
            tail = newNoode;
            return;
        }
        tail->next = newNoode;
        tail = tail->next;
    }

    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;

        if(head == NULL)
        {
            tail = NULL;
        }
    }

    int front()
    {
        return head->val;
    }

    int size()
    {
        return sz;
    }

    bool empty()
    {
        if(sz==0) return true;
        return false;
    }
};

int main()
{
    myQueue q;

    int n;
    cin>>n;

    while(n--)
    {
        int x;
        cin>>x;
        q.push(x);
    }

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    /* q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
    q.pop(); */
   
        



    cout<<endl;
    return 0;
}