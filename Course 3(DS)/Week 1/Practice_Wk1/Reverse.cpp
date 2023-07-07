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
        myVect.push_back(x);
    }

    for(int i=myVect.size()-1; i>=0; i--)cout<<myVect[i]<<" ";

    cout<<endl;
    return 0;
}