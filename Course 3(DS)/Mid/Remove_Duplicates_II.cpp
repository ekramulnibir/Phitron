#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> newList;

    int val;
    while(true)
    {
        cin>>val;

        if(val == -1) break;

        newList.push_back(val);
    }

    newList.sort();
    newList.unique();

    for(int gg:newList)
    {
        cout<<gg<<" ";
    }
    

    cout<<endl;
    return 0;
}