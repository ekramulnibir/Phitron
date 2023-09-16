#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str1,str2;
    cin>>str1>>str2;

    int n = str1.size();
    int m = str2.size();

    int dp[n+1][m+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
        }
    }

    int x,y,max = INT_MIN;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
                if(max<=dp[i][j])
                {
                    max = dp[i][j];
                    x = i;
                    y = j;
                }
            }
            else{
                dp[i][j] = 0;
            }
            
        }
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }


    string ans;
    int i = n,j=m;

    while(dp[x][y]!=0)
    {
        ans+=str1[x-1];
        x--;
        y--;
    }

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    
    

    cout<<endl;
    return 0;
}