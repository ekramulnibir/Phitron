#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

vector <pair<int,int>> adj;

bool compare(pi x, pi y)
{
    if(x.first < y.first) return true;
    else if(x.first == y.first)
    {
        if(x.second < y.second) return true;
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        int u,v;
        cin>>u>>v;
        adj.push_back(make_pair(u,v));
    }
    
    sort(adj.begin(), adj.end(), compare);
    
    for(auto p : adj)
    {
        cout<<p.first<<" "<<p.second<<endl;
    }

   
    

    cout<<endl;
    return 0;
}