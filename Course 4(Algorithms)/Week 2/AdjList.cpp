#include<bits/stdc++.h>
using namespace std;

const int N = 10000;

//vector <int> adj[N]; //directed
vector < pair<int,int> > adj[N];

int main()
{

    int n,m;
    cin>>n>>m;


    /* //directed
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<": ";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    } */

    //undirected
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<": ";
        for(auto j:adj[i]){
            cout<<"("<<j.first<<", "<<j.second<<")";
        }

        cout<<endl;
    }
    

    cout<<endl;
    return 0;
}