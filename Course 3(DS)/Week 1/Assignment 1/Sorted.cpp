#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,flag = 0;
        cin>>n;

        int ar[n];
        for(int i=0; i<n; i++) cin>>ar[i];

        for(int i=0; i<n-1; i++)
        {
            if(ar[i]>ar[i+1])
            {
                flag++;
                break;
            }
        }

        if(flag==0) cout<<"YES\n";
        else cout<<"NO\n";

    }
    

    return 0;
}