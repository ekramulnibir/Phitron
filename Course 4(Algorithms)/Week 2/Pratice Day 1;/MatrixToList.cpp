/* #include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int adjMat[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            cin>>adjMat[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            cout<<adjMat[i][j];
        }
        cout<<endl;
    }

   /*  vector<int> adj[n];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(adjMat[i][j]!=0)
            {
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
} */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int adjMat[n][n];

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            cin>>adjMat[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
        {
            cout<<adjMat[i][j];
        }
        cout<<endl;
    }

    vector<int> adj[n+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(adjMat[i][j]!=0)
            {
                adj[i].push_back(j);
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        cout<<"List "<<i<<" : ";
        for(int j:adj[i])
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}