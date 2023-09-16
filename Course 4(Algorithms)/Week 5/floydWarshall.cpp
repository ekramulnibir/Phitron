#include<bits/stdc++.h>
using namespace std;

const int INF = 1e5;

int main()
{
    int n,m;
    cin>>n>>m;

    int dist[n+1][n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;

        dist[u][v] = w;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j]==INF) cout<<"I ";
            else cout<< dist[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"-----------------------------\n";

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(dist[i][j]==INF) cout<<"I ";
            else cout<< dist[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}