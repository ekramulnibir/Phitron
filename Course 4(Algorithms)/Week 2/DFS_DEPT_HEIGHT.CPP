#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> adj[N];
bool visited[N];
int dept[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    cout<<"Visiting: "<<u<<endl;

    for(int v: adj[u])
    {
        if(visited[v]) continue;
        dept[v] = dept[u]+1;
        dfs(v);

        /* if(height[v]+1>height[u])
        {
            height[u] = height[v]+1;
        } */

        height[u] = max(height[v]+1,height[u]);
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
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int j: adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    dfs(1);

    for(int i=1; i<=n; i++)
    {
        cout<<"Dept of "<<i<<" is :"<<dept[i]<<endl;
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"Height of "<<i<<" is :"<<height[i]<<endl;
    }
    

    cout<<endl;
    return 0;
}