#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int terget = 1000-m;

        int ar[n];

        for(int i=0; i<n; i++)  cin>>ar[i];

        bool dp[n + 1][terget + 1];
        dp[0][0] = true;
        for (int i = 1; i <= terget; i++)
            dp[0][i] = false;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= terget; j++)
            {
                if (ar[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - ar[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

       if(dp[n][terget]) cout<<"YES\n";
       else cout<<"NO\n";
        

        
        

    }

    cout<<endl;
    return 0;
}