#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

bool dfs(int u, int p = -1)
{
    bool cycleDetected = false;

    visited[u] = true;
    for(auto v: adj[u])
    {
        if(v == p) continue;
        if(visited[v]) return true;
        cycleDetected |= dfs(v,u);
    }
    return cycleDetected;
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

    if(dfs(1)) cout<<"Cycle Detected";
    else cout<<"Cycle doesn't exists";
    

    cout<<endl;
    return 0;
}