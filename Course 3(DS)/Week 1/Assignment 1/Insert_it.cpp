#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> nVect;
    for(int i=0; i<n; i++) 
    {
        int x; cin>>x;
        nVect.push_back(x);
    }

    int m; cin>>m;
    vector<int> mVect;
    for(int i=0; i<m; i++) 
    {
        int x; cin>>x;
        mVect.push_back(x);
    }

    int x; cin>>x;

    nVect.insert(nVect.begin()+x,mVect.begin(),mVect.end());

    for(int i=0; i<nVect.size(); i++)
    {
        cout<<nVect[i]<<" ";
    }

    cout<<endl;
    return 0;
}