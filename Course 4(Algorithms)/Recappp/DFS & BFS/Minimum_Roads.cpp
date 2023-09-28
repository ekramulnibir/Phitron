#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    for(auto v: adj[u])
    {
        if(visited[v]) continue;
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

    vector<int> roads;
    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            dfs(i);
            roads.push_back(i);
        }
    }

    cout<<roads.size()-1<<endl;
    
    for(int i=0; i<roads.size()-1; i++)
    {
        cout<<roads[i]<< " "<<roads[i+1]<<endl;
    }

    cout<<endl;
    return 0;
}