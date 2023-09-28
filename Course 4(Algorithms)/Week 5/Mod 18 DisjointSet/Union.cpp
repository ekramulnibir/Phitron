#include<bits/stdc++.h>
using namespace std;

int parent[1000];

void Set(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i] = -1;
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

    if(leaderA != leaderB)
    {
        parent[leaderB] = leaderA;
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

    
    /* while(true)
    {
        int x;
        cin>>x;
        if(x == 0) break;
        cout<<find(x)<<endl;
    } */

    cout<<find(5);
    

    cout<<endl;
    return 0;
}