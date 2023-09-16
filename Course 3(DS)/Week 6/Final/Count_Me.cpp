#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    cin.ignore();
    
    while(t--)
    {
        string s;
        getline(cin,s);

        string word;
        stringstream ss(s);

        map<string,int> m;
        pair<string, int> pr;
        pr = make_pair("",0);

        while(ss>>word)
        {
            m[word]++;
            if(m[word]>pr.second)
            {
                pr.first = word;
                pr.second = m[word]; 
            }
        }

        cout<<pr.first<<" "<<pr.second<<endl;
    }
    
    return 0;
}