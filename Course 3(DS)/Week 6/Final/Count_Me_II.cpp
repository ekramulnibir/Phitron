#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int> > pq;
    int n;
    cin>>n;

    while(n--)
    {
        int x; cin>>x;
        pq.push(x);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int command; cin>>command;
        if(command == 0)
        {
            int x;
            cin>>x;
            pq.push(x);
        }

        else if(command == 1)
        {
            if(!pq.empty()) cout<<pq.top()<<endl;
            else cout<<"Empty"<<endl;
        }

        else{
            pq.pop();
            if(!pq.empty()) cout<<pq.top()<<endl;
            else cout<<"Empty"<<endl;
        }
    }
    

    cout<<endl;
    return 0;
}