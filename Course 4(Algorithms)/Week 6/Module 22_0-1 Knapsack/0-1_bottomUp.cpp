#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int w[n],v[n];
    for(int i=0; i<n; i++) cin>>w[i];
    for(int i=0; i<n; i++) cin>>v[i];
    
    int s;
    cin>>s;
    
    int dp[n+1][s+1];
    
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(i == 0 || j == 0) dp[i][j] = 0;
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=s; j++)
        {
            if (w[i - 1] <= j)
            {
                /*int take = dp[i-1][j-w[i-1]] + v[i-1];
                int wontTake = dp[i-1][j];
                
                dp[i][j] = max(take,wontTake);*/
                
                
                //dp state
                dp[i][j] = max(dp[i-1][j-w[n-1]]+v[i-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    cout<<endl<<dp[n][s]<<endl;
}
