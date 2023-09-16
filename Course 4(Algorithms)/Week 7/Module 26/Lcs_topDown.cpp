#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int lcs(string str1,int n,string str2,int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m] != -1) return dp[n][m];

    if(str1[n-1] == str2[m-1])
    {
        return dp[n][m] = lcs(str1,n-1,str2,m-1) + 1;
    }
    else{
        
        int ans1 = lcs(str1,n-1,str2,m);
        int ans2 = lcs(str1,n,str2,m-1);
        return  dp[n][m] = max(ans1,ans2);

    
        //return max(lcs(str1,n-1,str2,m),lcs(str1,n,str2,m-1));
    }

}

void setDp(int n,int m)
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++)
        {
            dp[i][j] = -1;
        }
    }
    
}

int main()
{
    string str1, str2;
    cin>>str1>>str2;
    

    setDp(str1.size(),str2.size());

    cout<<lcs(str1,str1.size(),str2,str2.size());


    cout<<endl;
    return 0;
}