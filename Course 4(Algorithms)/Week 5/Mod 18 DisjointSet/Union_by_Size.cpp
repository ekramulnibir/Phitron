#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentSize[1000];

void Set(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}

int find(int node)
{
    while(parent[node]!= -1)
    {
        node = parent[node];
    }
    return node;
}

void Dis_union(int a,int b)
{
    int leaderA = find(a);
    int leaderB = find(b);

    if(parentSize[leaderA] > parentSize[leaderB])
    {
        parent[leaderB] = leaderA;
        parentSize[leaderA] += parentSize[leaderB];
    }
    else{
        parent[leaderA] = leaderB;
        parentSize[leaderB] += parentSize[leaderA];
    }
}

int main()
{

    int n,m;
    cin>>n>>m;

    Set(n);

    while(m--)
    {
        int u,v;
        cin>>u>>v;

        Dis_union(u,v);
    }

    
    while(true)
    {
        int x;
        cin>>x;
        if(x == 0) break;
        cout<<find(x)<<endl;
    }
    

    cout<<endl;
    return 0;
}

