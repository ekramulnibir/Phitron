#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int knapSack(int w[],int v[],int n,int s)
{
    if(n == 0 || s == 0) return 0; //n<0

    if(dp[n][s] != -1) return dp[n][s];

    if(s >= w[n-1])
    {
        int take = knapSack(w, v, n-1,s - w[n-1]) + v[n-1];
        int wontTake = knapSack(w, v, n-1,s);

        return dp[n][s] = max(take,wontTake);
    }
    else{
        return dp[n][s] = knapSack(w, v, n-1, s);
    }
}

int main()
{
    int n;
    cin>>n;
    
    int val[n];
    for(int i=0; i<n; i++)cin>>val[i];

    int ar[n];
    for(int i=0; i<n; i++)cin>>ar[i];

    int S;
    cin>>S;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=S; j++)
        {
            dp[i][j] = -1;
        }
    }


    cout<<knapSack(ar,val,n,S);

    cout<<endl;
    return 0;
}