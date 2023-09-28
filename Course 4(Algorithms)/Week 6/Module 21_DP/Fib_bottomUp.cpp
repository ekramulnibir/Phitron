#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int save[N];

int fib(int n)
{
    if(n==0 || n==1) {return 1;}

    if(save[n]!= -1)
    {
        return save[n];
    }
    
    return save[n] = fib(n-1) + fib(n-2);
}

int main()
{
    
    int n;
    cin>>n;

    for(int i=0; i<=n; i++) save[i] = -1;

    cout<<fib(n)<<endl;
    
    cout<<endl;
    return 0;
}