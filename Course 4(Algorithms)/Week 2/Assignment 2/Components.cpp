#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector <int> adj[N];
bool visited[N];
vector <int> ans;

void bfs(int s)
{
    int count = 0;
    queue <int> q;
    q.push(s);
    visited[s] = true;
    

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;

        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v]=true;
    
        }
    }
    if(count>1)
    {
        ans.push_back(count);
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

    int cc = 0;

    for(int i=0; i<N; i++)
    {
        if(visited[i]) continue;
        bfs(i);
        cc++;
    }

    //cout<<cc;

    sort(ans.begin(),ans.end());

    for(int val:ans)
    {
        cout<<val<<" ";
    }

    cout<<endl;
    return 0;
}