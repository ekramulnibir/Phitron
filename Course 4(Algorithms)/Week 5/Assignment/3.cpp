#include<bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int u,v;
    long long int w;
    Edge(int u,int v,long long int w)
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
    map<int, bool> mp;

    while(m--)
    {
        int u,v;
        long long int w;
        cin>>u>>v>>w;
        mp[u] = true;
        mp[v] = true;
        
        vect.push_back(Edge(u,v,w));
    }

    int allConected = 0;
    
    for(auto it = mp.begin(); it != mp.end(); it++)
    {
        bool status = it->second;

        if(status == true)
        {
            allConected++;
        }
    }

    sort(vect.begin(),vect.end(),cmp);

    long long int minW = 0;

    for(Edge edge: vect)
    {
        int u = edge.u;
        int v = edge.v;
        long long int w = edge.w;

        int leaderU = dsu_find(u);
        int leaderV = dsu_find(v);

        if(leaderU == leaderV) continue;
        ans.push_back(edge);
        minW += w;
        dsu_union(u,v);  
    }

    if(allConected!=n) cout<<"-1\n";
    else cout<<minW<<endl;

}

