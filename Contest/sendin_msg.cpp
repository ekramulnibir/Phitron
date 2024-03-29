#include <bits/stdc++.h>
using namespace std;
const long long int N = 1e9+7;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,dif;
        cin >> n >> dif;
        int a[n], sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }

        int s = (dif + sum)/2;
        
        int dp[n + 1][s + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= s; i++)
            dp[0][i] = 0;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        cout<<dp[n][s] % N<<endl;

    }
    

    return 0;
}