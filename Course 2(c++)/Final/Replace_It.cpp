#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s,x;
        cin>>s>>x;

        int count = x.length();
        
        while(s.find(x)!=-1)
        {
            s.replace(s.find(x),count,"$");
        }

        cout<<s<<endl;

    }

    return 0;
}