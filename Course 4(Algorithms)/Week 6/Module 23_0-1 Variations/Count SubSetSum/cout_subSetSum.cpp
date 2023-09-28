//own wayyy
#include <bits/stdc++.h>
using namespace std;

bool subSetSum(int n,int s,int num[],int &count)
{
    if(n==0)
    {
        if(s==0)
        {   
            count++;
            return true;
        }
        else return false;
    }
    
    if(s >= num[n-1])
    {
        bool take = subSetSum(n-1,s-num[n-1],num,count);
        bool wontTake = subSetSum(n-1, s, num,count);
        return  take || wontTake;
    }
    else
    {
        return subSetSum(n-1,s,num,count);
    }
    
    
}

int main()
{
    int n,count = 0;
    cin>>n;
    
    int num[n];
    for(int i=0; i<n; i++) cin>>num[i];
    
    int s;
    cin>>s;
    
    if(subSetSum(n,s,num,count))cout<<"YES\n";
    else cout<<"NO\n";
    
    cout<<count<<endl;
    
    return 0;
}
