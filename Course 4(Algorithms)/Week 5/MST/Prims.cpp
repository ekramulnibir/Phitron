#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

const int N = 1e5+5;
vector<pi> adj[N];
bool vis[N];

class Edge
{
    public:
    int u,v,w;
    Edge(int u,int v,int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class cmp
{
    public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }

};

void prims(int source)
{
    priority_queue<Edge, vector <Edge>, cmp> pq;
    vector<Edge> edgeList;
    pq.push(Edge(source,source,0));
    while(!pq.empty())
    {
        Edge parent = pq.top();
        pq.pop();
        int u = parent.u;
        int v = parent.v;
        int w = parent.w;
        if(vis[v])continue;
        vis[v] = true;
        edgeList.push_back(parent);

        for(int i=0; i<adj[v].size(); i++)
        {
            pi child = adj[v][i];
            if(!vis[child.first])
            {
                pq.push(Edge(v,child.first,child.second));
            }
            
        }
    }

    for(Edge val: edgeList)
    {
        cout<<val.u<<" "<<val.v<<" "<<val.w<<endl;
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    prims(1);
    

    cout<<endl;
    return 0;
}

/* Input:
8 11
1 5 2
1 2 4
1 4 10
5 4 5
2 4 8
2 3 18
3 4 11
4 8 9
4 7 11
7 6 1
8 6 2 */