#include<bits/stdc++.h>
using namespace std;

int parent[100];
int parentSize[100];

void dsu_set()
{
    for(int i=0; i<100; i++) 
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

    cout<<findLeader(1)<<endl;
    return 0;
}