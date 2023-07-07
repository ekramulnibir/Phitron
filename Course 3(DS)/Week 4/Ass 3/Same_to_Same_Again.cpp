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
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }

        delete deleteNode;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};

class myQueue
{
    public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz=0;

    void push(int val){
        sz++;
        Node *newNode = new Node(val);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = tail->next;
    }

    void pop()
    {
        sz--;        
        Node *deleteHead = head;
        head = head->next;
        if(head == NULL)
        {
            tail = NULL;
            delete deleteHead;
            return;
        }
        head -> prev = NULL;
        delete deleteHead;
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
        if(sz == 0) return true;
        return false;
    }


};

int isSame(myStack s, myQueue q)
{
    while(!s.empty() && !q.empty())
    {
        if(s.top() != q.front())
        {
            return -1;
        }
        s.pop();
        q.pop();
    }

    return 1;
}

int main()
{
    myStack S;
    myQueue Q;

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        S.push(x);
    }
    for(int i=0; i<m; i++)
    {
        int x; cin>>x;
        Q.push(x);
    }

    if(n==m)
    {
        (isSame(S,Q)==-1)? cout<<"NO\n" : cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
   

    

    cout<<endl;
    return 0;
}