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

int mx = INT_MIN;

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
            mx = max(mx,parentSize[leaderA]);
        }
        else{
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
            mx = max(mx,parentSize[leaderB]);
        }
        
    }

}

int main()
{
    dsu_set();

    int n,m;
    cin>>n>>m;
    int cc = n;
    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        int leaderU = findLeader(u);
        int leaderV = findLeader(v);

        if(leaderU != leaderV)
        {
            cc--;
            dsu_union(u,v);
        }
        cout<<cc<<" "<<mx<<endl;
    }

    return 0;
}