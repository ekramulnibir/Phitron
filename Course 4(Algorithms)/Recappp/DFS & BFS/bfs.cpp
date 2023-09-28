#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> adj[N];
bool visited[N];

int level[N];

void bfs(int source)
{
    queue<int> q;
    q.push(source);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = true;
        cout<<"Visiting : "<<u<<endl;

        for(auto v: adj[u])
        {
            if(visited[v]) continue;
            q.push(v);
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

    bfs(1);

    

    

    cout<<"*****\n";
    for(int i=1; i<=n; i++) 
    cout<<"Level of "<<i<<" : "<<level[i]<<endl;;
    
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