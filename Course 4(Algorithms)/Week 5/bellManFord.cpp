#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int w;

    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;

    vector <Edge> adj;

    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        Edge ed(u,v,w);

        adj.push_back(ed);
    }

    int dist[n+1];
    for(int i=1; i<=n; i++) dist[i] = INT_MAX;

    dist[1] = 0;

    for(int i=1; i<n-1; i++)
    {
        for(int j=0; j<adj.size(); j++)
        {
            Edge ed = adj[j];
            int u = ed.u;
            int v = ed.v;
            int w = ed.w;

            if(dist[u]+w < dist[v])
            {
                dist[v] = dist[u]+w;
            } 
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"Distance of "<<i<<" : "<<dist[i]<<endl;
    }

    //cycle detection
    //we will try to relax the edges after
    //n-1 iteration menas n times
    //if the edge is not relaxed in n iteration
    //it means no cycle 
    //else cycle exists

    bool cycleDetected = false;

    for(int j=0; j<adj.size(); j++)
    {
        Edge ed = adj[j];
        int u = ed.u;
        int v = ed.v;
        int w = ed.w;

        if(dist[u]+w < dist[v])
        {
            cycleDetected = true;
            break;
            dist[v] = dist[u]+w;
        } 
    }

    if(cycleDetected) cout<<"Cycle Dectected!\n";
    else cout<<"No cycle detected\n";



    cout<<endl;
    return 0;
}