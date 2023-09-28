#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int u;
    int v;
    int w;
    Edge(int u,int v,int w)
    {
        this->u = u;;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;

    vector<Edge> ed;
    for(int i=0; i<m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ed.push_back(Edge(u,v,w));
    }

    int dist[n+1];
    for(int i=0; i<=n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[1] = 0;

    for(int i=1; i<=n-1; i++)
    {
        for(int j=0; j<ed.size(); j++)
        {
            Edge edge = ed[j];
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
            if(dist[u]+w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    bool flag = false;

    for(int j=0; j<ed.size(); j++)
    {
        Edge edge = ed[j];
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
        if(dist[u]+w < dist[v])
        {
            flag = true;
            break;
            dist[v] = dist[u] + w;
        }
    }

    if(flag) cout<<"Cycle Detected\n";
    else 
    {
        for(int i=1; i<=n; i++)
        {
            cout<<"Distance of "<<i<<" : "<<dist[i]<<endl;
        }
    }
    cout<<endl;
    return 0;
}