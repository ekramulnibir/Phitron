#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n; cin>>n;
    long long ar[n];
    long long prefix_sum[n];
    long long sum = 0;

    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
        sum += ar[i];
        prefix_sum[i] = sum;
    }

    for(int j=n-1; j>=0; j--)
    {
        cout<<prefix_sum[j]<<" ";
    }

    cout<<endl;
    return 0;
}