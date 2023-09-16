#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool visited[N];

int dept[N];
int height[N];

void dfs(int u)
{
    visited[u] = true;
    cout<<"Visiting: "<<u<<endl;
    for(auto v:adj[u])
    { 
        dept[v] = dept[u]+1;
        if(visited[v]) continue;
        dfs(v);
        height[u] = max(height[u],height[v]+1);
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

    dfs(1);

    cout<<"*****\n";
    for(int i=1; i<=n; i++) 
    cout<<"Dept of "<<i<<" : "<<dept[i]<<endl;;
    cout<<"*****\n";
    for(int i=1; i<=n; i++) 
    cout<<"Height of "<<i<<" : "<<height[i]<<endl;

    cout<<endl;
    return 0;
}

/* input
11
10
1 2
1 3
2 4
2 5
4 6
4 8
5 7
5 9
3 10
3 11 
*/