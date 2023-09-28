#include<bits/stdc++.h>
using namespace std;

int main()
{
    //vector<int> v = {50,45,40,35,30,25,31};
    
    int n; cin>>n;
    
    vector<int> v;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
    
        v.push_back(x);
        
        int curr_idx = v.size()-1;
        
        
        while(curr_idx != 0)
        {
            int par_idx = (curr_idx-1)/2;
            if(v[par_idx] < v[curr_idx])
                swap(v[par_idx], v[curr_idx]);
            else break;
            
            curr_idx = par_idx;
        }
        
    }
    
    
    
    
    for(int val:v) cout<<val<<" ";

    cout<<endl;
    return 0;
}