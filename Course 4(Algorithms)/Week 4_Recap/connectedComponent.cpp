#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
bool visited[N];

void dfs(int source)
{
    visited[source] = true;
    for(int v:adj[source])
    {
        if(!visited[v])
        dfs(v);
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
        adj[v].push_back(u);
    }

    int count = 0;

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            count++;
            dfs(i);
        }
    }

    cout<<count<<endl;

     

    cout<<endl;
    return 0;
}