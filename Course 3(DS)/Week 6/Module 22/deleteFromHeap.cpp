#include<bits/stdc++.h>
using namespace std;

void insert(vector<int> &v, int x)
{
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

void deleteFromHeap(vector<int> &v)
{
    v[0] = v[v.size()-1];
    v.pop_back();

    int curr_idx = 0;

    while(true)
    {
        int left_idx = curr_idx * 2 +1;
        int right_idx = curr_idx * 2 +2;
        int last_idx = v.size()-1;

        if(left_idx<=last_idx && right_idx<=last_idx)
        {
            if(v[left_idx] >= v[right_idx] && v[curr_idx] < v[left_idx]){
                swap(v[curr_idx],v[left_idx]);
                curr_idx = left_idx;
            }else if(v[right_idx] >= v[left_idx] && v[curr_idx] < v[right_idx]){
                swap(v[curr_idx],v[right_idx]);
                curr_idx = right_idx;
            }else{
                break;
            }

        }
        else if(left_idx<=last_idx)
        {
            if(v[curr_idx] < v[left_idx]){
                swap(v[curr_idx],v[left_idx]);
                curr_idx = left_idx;
            }else{
                break;
            }

        }
        else if(right_idx<=last_idx)
        {
            if(v[curr_idx] < v[right_idx]){
                swap(v[curr_idx],v[right_idx]);
                curr_idx = right_idx;
            }else{
                break;
            }

        }
        else break;
    }



}

void print(vector<int> v)
{
    for(int val:v) cout<<val<<" ";
}

int main()
{
    vector<int> v;
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        int x;
        cin>>x;

        insert(v,x);
    }

    print(v);

    deleteFromHeap(v);
    cout<<endl;

    print(v);

    cout<<endl;
    return 0;
}