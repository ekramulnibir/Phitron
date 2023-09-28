#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 1e5+5;
const int INF = INT_MAX;
vector<pii> adj[N];
vector<int> dist(N,INF);
vector<bool> visited(N);

void dijkstra(int source)
{
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    dist[source] = 0;
    pq.push(make_pair(dist[source],source));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(pii vpair: adj[u])
        {
            int v = vpair.second;
            int w = vpair.first;

            if(dist[v] > dist[u]+w)
            {
                dist[v] = dist[u]+w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }
}



int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back(make_pair(w,v));
        adj[v].push_back(make_pair(w,u));
    }

    dijkstra(1);

    for(int i=1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<" : "<<dist[i]<<endl;
    }

    cout<<endl;
    return 0;
}

/* 
5
7
1 2 10
1 3 2
2 5 2
2 4 3
2 3 1
3 4 2
4 5 7 


7
8
1 2 3
1 3 5
3 4 1
4 6 1
2 5 6
5 6 1
5 7 2
3 7 12 
*/