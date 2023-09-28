#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector <int> adj[N];
bool visited[N];


void dfs(int u,int &count)
{
    visited[u] = true;
    count++;
    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dfs(v,count);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    int l,count = 0;
    cin>>l;

    dfs(l,count);

    cout<<count-1<<endl;

    return 0;
}