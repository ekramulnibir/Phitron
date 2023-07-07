#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int spaces=n-2;
    int front_space = 0;

    for(int i=1; i<=n; i++)
    {
        for(int fs=0; fs<front_space; fs++)
        {
            cout<<" ";
        }
        if(i<=n/2)
        {
            cout<<"\\";
            for(int j=1; j<=spaces; j++)
            {
                cout<<" ";
            }
            cout<<"/\n";
            spaces -=2;
            front_space++;
        }
        else if(i>(n/2)+1){
            cout<<"/";
            for(int j=1; j<=spaces; j++)
            {
                cout<<" ";
            }
            cout<<"\\\n";
            spaces +=2;
            front_space--;
        }
        else{
            cout<<"X"<<endl;
            spaces+=2;
            front_space--;
        }
        
        
    }

    return 0;
}