#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue <string> q;

    int n; cin>>n;
    while(n--)
    {
        int a; string str;
        cin>>a;
        if(a==0)
        {
            cin>>str;
            q.push(str);
        }
        else{
            if(q.empty()) cout<<"Invalid\n";
            else
            {
                cout<<q.front()<<endl;
                q.pop();
            }
            
        }
    }

    cout<<endl;
    return 0;
}