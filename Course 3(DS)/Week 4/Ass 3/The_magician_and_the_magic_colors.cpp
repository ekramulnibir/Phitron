#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        stack<char> myStack;
        stack<char> newStack;

        int n; cin>>n;

        while(n--)
        {
            char c; cin>>c;
            if(myStack.empty()) myStack.push(c);

            else if(myStack.top()==c)
            {
                myStack.pop();
            }

            else if((myStack.top()=='R' && c=='B') || (myStack.top()=='B' && c=='R'))
            {
                myStack.pop();
                myStack.push('P');
            }

            else if((myStack.top()=='R' && c=='G') || (myStack.top()=='G' && c=='R'))
            {
                myStack.pop();
                myStack.push('Y');
            }

            else if((myStack.top()=='B' && c=='G') || (myStack.top()=='G' && c=='B'))
            {
                myStack.pop();
                myStack.push('C');
            }

            else{
                myStack.push(c);
            }
            
        }

        while (!myStack.empty())
        {
            if (newStack.empty() || myStack.top() != newStack.top())
            {
                newStack.push(myStack.top());
            }
            else{
                newStack.pop();
            }

            myStack.pop();
            
        }

        while(!newStack.empty())
        {
            cout<<newStack.top();
            newStack.pop();
        }

        cout<<endl;

        /* while(!myStack.empty())
        {
            cout<<myStack.top();
            myStack.pop();
        } */ 

    }
    


    cout<<endl;
    return 0;
}