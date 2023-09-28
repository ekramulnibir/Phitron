#include<bits/stdc++.h>
using namespace std;

int parent[9] = {-1,-1,1,1,2,2,-1,6,-1};
int findLeader(int i)
{
    while(parent[i]!=-1)
    {
        i = parent[i];
    }
    return i;
}

int main()
{
    int n;
    cin>>n;

    cout<<findLeader(n)<<endl;

    return 0;
}