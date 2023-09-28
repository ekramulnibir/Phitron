#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int main()
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    int t;
    cin>>t;

    while(t--)
    {
        pii paiR;
        cin>>paiR.first>>paiR.second;
        pq.push(paiR);
    }

    while(!pq.empty())
    {
        pii x;
        x = pq.top();
        pq.pop();
        cout<<x.first<<" "<<x.second<<endl;
    }



    cout<<endl;
    return 0;
}