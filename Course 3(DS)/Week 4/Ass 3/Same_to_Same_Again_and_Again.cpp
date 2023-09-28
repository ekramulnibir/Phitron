#include<bits/stdc++.h>
using namespace std;

int isSame(stack<int> s, queue<int> q)
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
    stack<int> myStack;
    queue<int> Q;

    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        myStack.push(x);
    }
    for(int i=0; i<m; i++)
    {
        int x; cin>>x;
        Q.push(x);
    }

    if(n==m)
    {
        (isSame(myStack,Q)==-1)? cout<<"NO\n" : cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
   

    

    cout<<endl;
    return 0;
}