#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int a[n],b[n];

    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];

    vector <int> myVect;
    
    for(int i=0; i<n; i++) myVect.push_back(b[i]);
    for(int i=0; i<n; i++) myVect.push_back(a[i]);

    for(int x:myVect)
    cout<<x<<" ";

    cout<<endl;
    return 0;
}