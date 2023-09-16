#include<bits/stdc++.h>
using namespace std;

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

bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

const int N = 1e5 + 5;
int parent[N];
int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
int dsu_find(int node)
{
    while (parent[node] != -1)
    {
        node = parent[node];
    }
    return node;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    dsu_set(n);

    vector<Edge> vect;
    vector<Edge> ans;

    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        
        vect.push_back(Edge(u,v,w));
    }
    sort(vect.begin(),vect.end(),cmp);

    for(Edge edge: vect)
    {
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;

        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);

        if(leaderU == leaderV) continue;
        ans.push_back(edge);
        dsu_union(u,v);
        
    }

    for(Edge edge: ans)
    {
        cout<<edge.u<<" "<<edge.v<<" "<<edge.w<<endl;
    }

}

/* INPUT
7 11
1 2 5
1 3 7
3 2 9
3 5 8
5 6 5
3 6 7
2 4 6
2 6 15
4 6 8
4 7 11
6 7 9 
*/
