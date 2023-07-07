#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    while(n--)
    {
        stack<char> myStack;
        string str;
        cin>>str;

        for(char c:str)
        {
            if(myStack.empty() || myStack.top()==c) myStack.push(c);
            else myStack.pop();
        }

        (myStack.empty())? cout<<"YES\n": cout<<"NO\n";

    }
    
    
}