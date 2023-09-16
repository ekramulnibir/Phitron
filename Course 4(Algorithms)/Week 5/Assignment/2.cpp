#include<bits/stdc++.h>
using namespace std;

const long long int INF = 1e18+50;

int main()
{
    int n,m;
    cin>>n>>m;

    long long int dist[n+1][n+1];

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
        int u,v;
        long long int w;
        cin>>u>>v>>w;

        if(dist[u][v] == INF || dist[u][v] > w)
        {
            dist[u][v] = w;
        }

       
    }


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

    

    int q;
    cin>>q;

    while(q--)
    {
        int x,y;
        cin>>x>>y;

        if(dist[x][y] != INF)
        {
             cout<<dist[x][y]<<endl;
        }
        else
        {
            cout<<"-1"<<endl;
        }

       
    }



    cout<<endl;
    return 0;
}