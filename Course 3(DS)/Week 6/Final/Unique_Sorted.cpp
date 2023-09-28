#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        set<int> st;
        vector<int> v;

        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            st.insert(x);
        }
        for(auto it = st.begin(); it!=st.end(); it++) v.push_back(*it);
        reverse(v.begin(),v.end());

        for(int val: v) cout<<val<<" ";

        cout<<endl;
    }
    

    
    return 0;
}