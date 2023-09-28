#include<bits/stdc++.h>
using namespace std;

int parent[100];
int parentRank[100];

void dsu_set()
{
    for(int i=0; i<100; i++) 
    {
        parent[i] = -1;
        parentRank[i] = 1;
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
        if(parentRank[leaderA]>parentRank[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if(parentRank[leaderB] > parentRank[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else{
            parent[leaderB] = leaderA;
            parentRank[leaderA]++;
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

        int leaderU = findLeader(u);
        int leaderV = findLeader(v);

        if(leaderU == leaderV) cout<<"Cycle Detected\n";
        else dsu_union(u,v);
    }

    cout<<findLeader(5)<<endl;
    return 0;
}