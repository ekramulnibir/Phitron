#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int ar[n];
        int copy[n];

        for(int i=0; i<n; i++)
        {
            cin>>ar[i];
            copy[i] = ar[i];
        }
        sort(ar,ar+n);

        for(int i=0; i<n; i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<ar[i]<<" ";
        }
    }

    cout<<endl;
    return 0;
}