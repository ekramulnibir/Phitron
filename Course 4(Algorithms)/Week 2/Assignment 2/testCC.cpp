#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector <int> adj[N];
bool visited[N];

void dfs(int u,int &count)
{
    visited[u] = true;
    count++;
    
    for(int v:adj[u])
    {
        if(visited[v])continue;
        dfs(v,count);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        //adj[v].push_back(u);
    }

    //dfs(1);

    int cc = 0;

    for(int i=1; i<=1000; i++)
    {
        int count = 0;
        if(visited[i]) continue;
        dfs(i,count);
        cout<<count<<endl;
    }

    //cout<<cc;

    cout<<endl;
    return 0;
}