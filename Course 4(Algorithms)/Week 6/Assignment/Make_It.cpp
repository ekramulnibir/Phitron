#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int dp[N];

bool isPerfect(int n)
{
    if(n==1) return true;
    if(n<1) return false;

    if(dp[n]!= -1) return dp[n];

    if(n%2==0)
    {
        bool div = isPerfect(n/2);
        bool sub = isPerfect(n-3);

        return dp[n] = div || sub;
    }
    else{
        return dp[n] = isPerfect(n-3);
    }
    
}

int main()
{
    int n;
    cin>>n;

    for(int i=0; i<=N; i++) dp[i] = -1;

    int ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];

    isPerfect(N);

    for(int i=0; i<n; i++)
    {
        if(isPerfect(ar[i]))cout<<"YES\n";
        else cout<<"NO\n";
    }

}