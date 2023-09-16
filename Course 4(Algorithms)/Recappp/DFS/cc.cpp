#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    visited[u] = true;
    cout<<"Visiting: "<<u<<endl;
    for(auto v:adj[u])
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

    int cc= 0;

    for(int i=1; i<=n; i++)
    {
        if(!visited[i]) 
        {
            dfs(i);
            cc++;
        }
        
    }

    cout<<cc<<endl;

    
    return 0;
}

/* input
8
5
1 2
1 3
2 4
2 5
6 7

//output 3
*/