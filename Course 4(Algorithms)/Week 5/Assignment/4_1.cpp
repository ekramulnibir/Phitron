#include<bits/stdc++.h>
using namespace std;

const long long int INF = LLONG_MAX;

class Edge{
    public:
    int u;
    int v;
    long long int w;

    Edge(int u,int v,long long int w)
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
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        Edge ed(u,v,w);

        adj.push_back(ed);
    }

    long long int dist[n+1];
    for(int i=1; i<=n; i++) dist[i] = INF;

    int s;
    cin>>s;
    
    dist[s] = 0;

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

    int q;
    cin>>q;

    while(q--)
    {
        
        int x;
        cin>>x;
        
        if(cycleDetected) continue; 

        if(dist[x]>1000000000 || dist[x]<-1000000000 )
        {
            cout<<"Not Possible\n";
        }
        else{
            cout<<dist[x]<<endl;
        }
        
    }
    if(cycleDetected) cout<<"Negative Cycle Detected\n";

    return 0;
}