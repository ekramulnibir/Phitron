#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector <int> adj[N];
bool visited[N];
int level[N];

int bfs(int s,int x)
{
    int distance = -1;
    queue <int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if(u == x)
        {
            distance = level[u];
            return distance;
        }

        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
            level[v] = level[u] + 1;
        }
    }

    return distance;
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

    int Q;
    cin>>Q;

    for(int i=0; i<Q; i++)
    {
        int u,v;
        cin>>u>>v;

        for (int i = 0; i < N; ++i) visited[i] = false;

        cout<<bfs(u,v)<<endl;
    }
    

    cout<<endl;
    return 0;
}