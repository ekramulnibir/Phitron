#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int ar[n],sum = 0;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        sum+=ar[i];
    }

    if(sum%2 == 0)
    {
        int s = sum/2;
        bool dp[n+1][s+1];

        dp[0][0] = true;

        for(int i=1; i<=s; i++) dp[0][i] = false;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=s; j++)
            {
                if(ar[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-ar[i-1]] || dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        if(dp[n][s]) cout<<"possible\n";
        else cout<<"Not possible\n";
    }
    else{
         cout<<"Not possible\n";
    }


    

    cout<<endl;
    return 0;
}