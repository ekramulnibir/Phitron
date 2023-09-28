#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int parent[N];
int parentSize[N];

void dsu_set()
{
    for(int i=0; i<N; i++) 
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int findLeader(int i)
{
    while(parent[i]!=-1)
    {
        i = parent[i];
    }
    return i;
}

void dsu_union(int a, int b)
{
    int leaderA = findLeader(a);
    int leaderB = findLeader(b);

    if(leaderA != leaderB)
    {
        if(parentSize[leaderA]>parentSize[leaderB])
        {
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else{
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
        
    }

}

int main()
{
    dsu_set();

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        dsu_union(u,v);
    }
    map<int,bool> mp;

    for(int i=1; i<=n; i++)
    {
        int leader = findLeader(i);
        mp[leader] = true;
    }

    vector<int> roads;
    for(auto v:mp)
    {
        roads.push_back(v.first);
    }

    cout<<roads.size()-1<<endl;
    for(int i=0; i<roads.size()-1; i++)
    {
        cout<<roads[i]<<" "<<roads[i+1]<<endl;
    }

    
    return 0;
}