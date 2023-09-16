#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
int adjMat[N][N];

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }

    for(int i=1; i<=n; i++){
        for(int j=0; j<m; j++){
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}