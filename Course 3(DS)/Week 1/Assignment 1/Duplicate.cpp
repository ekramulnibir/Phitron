#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> vect;

    for(int i=0; i<n; i++)
    {
        int x; cin>>x;
        vect.push_back(x);
    }

    for(auto it= vect.begin(); it<vect.end()-1; it++)
    {
        for(auto it_j = it+1; it_j<vect.end(); it_j++)
        {
            if(*it == *it_j)
            {
                cout<<"YES";
                return 0;
            }
        }
    }

    cout<<"NO";

    cout<<endl;
    return 0;
}