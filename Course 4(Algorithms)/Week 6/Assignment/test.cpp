#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N];


int main()
{
    
    int n;
    cin>>n;

    for(int i=0; i<=N; i++) dp[i] = -1;

    int ar[n];
    for(int i=0; i<n; i++) 
    {
        cin>>ar[i];
    }

    dp[1]=1;

    for(int i=1; i<=N; i++)
    {
        dp[i+3]  = 1;
        i = i+3;
    }

    for(int i=1; i<=N; i++)
    {
        dp[i*2] = 1;
        i = i*2;
    }

    for(int i=1; i<100; i++)
    {
        cout<<i<<" : "<<dp[i]<<endl;
    }

    
}