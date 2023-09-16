#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector <int> adj[N];
bool visited[N];

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

    int k;
    cin>>k;

    int count = 0;

    for(int i=0; i<n; i++)
    {
        /* if(i == k)
        {
            cout<<sizeof(adj[i])<<endl;
        } */

        

        if(i == k)
        {
            for(int j:adj[i])
            {
                count++;
            }
        }

    }

    cout<<count<<endl;


    return 0;
}