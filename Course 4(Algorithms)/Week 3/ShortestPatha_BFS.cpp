#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector <int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    level[s] = 0;
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<"Visiting : "<<u<<endl;

        for(int v:adj[u])
        {
            if(visited[v])  continue;
            q.push(v);
            visited[v] = true;
            parent[v] = u;
            level[v] = level[u] + 1;
        }
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

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    int s,d;
    cin>>s>>d;

    bfs(s);

    cout<<"Shortest Distance from "<<s<<" to "<<d<<" is "<<level[d]<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<"Parent of "<<i<<" is "<<parent[i]<<endl;
    }

    vector<int> path;
    int current = d;

    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(),path.end());

    for(int p:path)
    {
        cout<<p<<" ";
    }

    

    cout<<endl;
    return 0;
}