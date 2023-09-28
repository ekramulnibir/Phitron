#include<bits/stdc++.h>
using namespace std;

int parent[1000];
int parentLevel[1000];

void Set(int n)
{
    for(int i=0; i<=n; i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;
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

    if(parentLevel[leaderA] > parentLevel[leaderB])
    {
        parent[leaderB] = leaderA;
    }
    else if(parentLevel[leaderA] < parentLevel[leaderB])
    {
        parent[leaderA] = leaderB;
    }
    else{
        parent[leaderB] = leaderA;
        parentLevel[leaderA]++;
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

        int leaderU = find(u);
        int leaderV = find(v);

        if(leaderU != leaderV)
        {
            Dis_union(u,v);
        }
        else{
            cout<<"Cycle detected between "<<u<<" and "<<v<<endl;
        }
    }

    
    cout<<find(5);
    

    cout<<endl;
    return 0;
}

