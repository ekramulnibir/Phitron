#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector <int> myVect;

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x>=1)myVect.push_back(1);
        else if(x<0) myVect.push_back(2);
        else myVect.push_back(0);
        
    }

    for(int x:myVect)
    {
        cout<<x<<" ";
    }

    cout<<endl;
    return 0;
}