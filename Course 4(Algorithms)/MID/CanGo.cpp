#include<bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 100005;
const long long int INF = LLONG_MAX;
vector <pii> adj[N];
vector <long long int> dist(N, INF);
vector <bool> visited(N);
 

void dijkstra(int source)
{
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[source] = 0;
    pq.push(make_pair(dist[source],source));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for(pii vpair:adj[u]) //auto can be used as well
        {
            int v = vpair.first;
            int w = vpair.second;

            if(visited[v]) continue;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
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

        adj[u].push_back(make_pair(v,w));
        //adj[v].push_back(make_pair(u,w));
    }

    int source;
    cin>>source;

    dijkstra(source);

    int q;
    cin>>q;

    for(int i=0; i<q; i++)
    {
        int des,cost;
        cin>>des>>cost;

        if(dist[des]<=cost) cout<<"YES\n";
        else cout<<"NO\n";
    }
    


    /* for(int i=1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<" : "<<dist[i]<<endl;
    } */

    cout<<endl;
    return 0;
}