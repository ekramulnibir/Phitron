#include<bits/stdc++.h>
using namespace std;

int main()
{
    string names;
    getline(cin,names);
    
    /* int index = names.find("Ratul");
    (index != -1)?cout<<"YES":cout<<"NO"; */

    stringstream ss(names);
    string temp;

    while(ss>>temp)
    {
        if(temp == "Ratul"){cout<<"YES"; return 0;}
    }
    cout<<"NO";
    return 0;
}