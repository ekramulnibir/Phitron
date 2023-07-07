#include<bits/stdc++.h>
using namespace std;

int main()
{
    /* list <int> newList(10,5);

    for(auto it=newList.begin(); it!=newList.end(); it++)
    {
        cout<<*it<<" "; //derefrence
    }

    cout<<endl;

    for(int val:newList)
    {
        cout<<val<<" ";
    } */

    list <int> newlist(5,5);
    cout<<newlist.size()<<endl;

    newlist.insert(next(newlist.begin(),2),100);

    for(int val:newlist) cout<<val<<" ";

    cout<<endl;
    return 0;
}