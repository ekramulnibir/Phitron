#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    string val;
    Node *next;
    Node *prev;

    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert(Node *&head, Node *&tail, string val)
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
    while(head!=NULL)
    {
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void r_print(Node *tail)
{
    while(tail!=NULL)
    {
        cout<<tail->val<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}

int visit(Node *head, Node *&ptr, string str)
{
    Node *temp = head;
    while(temp!=NULL)
    {
        if(temp->val == str)
        {
            ptr = temp;
            //cout<<ptr->val<<" "; 
            return 1;
        }

        temp = temp->next;
    }

    //cout<<ptr->val<<endl;

    return -1;
    /* Node *temp = ptr;
    while(ptr->val != str)
    {
        if(ptr->next == NULL)
        {
            ptr = temp;
            return -1;
        }

        ptr = ptr->next;
    }

    return 1; */
}

int decision_prev(Node *head,Node *tail,Node *&ptr)
{
    if(ptr == head)
    {
        return -1;
    }
    else{
        ptr = ptr->prev;
        return 1;
    }
}

int decision_next(Node *head,Node *tail,Node *&ptr)
{
    if(ptr == tail)
    {
        return -1;
    }
    else{
        ptr = ptr->next;
        return 1;
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    string val;

    while(true)
    {
        cin>>val;
        if(val == "end") break;

        insert(head,tail,val);
    }

    Node *ptr = head;

    int n;
    cin>>n;
    string decision;

    while(n--)
    {
        cin>>decision;
        if(decision=="visit")
        {
            string str;
            cin>>str;

            if(visit(head,ptr,str)!=-1)
            {
                cout<<ptr->val<<endl;
            }
            else{
                cout<<"Not Available"<<endl;
            }
        }

        else if(decision=="prev")
        {
            if(decision_prev(head,tail,ptr)==-1)
            {
                cout<<"Not Available"<<endl;
            }
            else{
                cout<<ptr->val<<endl;
            }

        }

        else if(decision =="next"){
            if(decision_next(head,tail,ptr)==-1)
            {
                cout<<"Not Available"<<endl;
            }
            else{
                cout<<ptr->val<<endl;
            }
        }

    }
    
    return 0;
}