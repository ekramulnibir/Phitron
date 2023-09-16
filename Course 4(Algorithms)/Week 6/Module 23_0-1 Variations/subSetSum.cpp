#include<bits/stdc++.h>
using namespace std;

bool subSetSum(int n,int ar[],int s)
{
    if(n==0)
    {
        if(s==0) return true;
        else return false;
    }

    if(ar[n-1] <= s)
    {
        int op1 = subSetSum(n-1,ar,s-ar[n-1]);
        int op2 = subSetSum(n-1,ar,s);
        return op1 || op2;
    }
    else
    {
        return subSetSum(n-1,ar,s);
    }
    
}

int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)cin>>ar[i];

    int s;
    cin>>s;

    if(subSetSum(n,ar,s)) cout<<"Yes\n";
    else cout<<"No\n";
    

    cout<<endl;
    return 0;
}