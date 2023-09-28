#include<bits/stdc++.h>
using namespace std;

int knapSack(int w[],int v[],int n,int s)
{
    if(n == 0 || s == 0) return 0; //n<0

    if(s >= w[n-1])
    {
        int take = knapSack(w, v, n-1,s - w[n-1]) + v[n-1];
        int wontTake = knapSack(w, v, n-1,s);

        return max(take,wontTake);
    }
    else{
        return knapSack(w, v, n-1, s);
    }
}

int main()
{
    int n;
    cin>>n;

    int ar[n];
    for(int i=0; i<n; i++)cin>>ar[i];
    
    int val[n];
    for(int i=0; i<n; i++)cin>>val[i];

    int knapsack;
    cin>>knapsack;


    cout<<knapSack(ar,val,n,knapsack);

    cout<<endl;
    return 0;
}