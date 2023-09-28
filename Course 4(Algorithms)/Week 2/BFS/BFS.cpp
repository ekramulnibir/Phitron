#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector <int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)
{
    queue <int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<"Visiting : "<<u<<endl;

        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
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
        cout<<"Level "<<i<<" : ";
        for(auto j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    bfs(1);

    for(int i=1; i<=n; i++)
    {
        cout<<"Level of "<<i<<" : "<<level[i]<<endl;
    }



    cout<<endl;
    return 0;
}