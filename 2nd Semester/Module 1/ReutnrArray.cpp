#include<bits/stdc++.h>
using namespace std;

int *init(int n)
{
    int *ptr;
    ptr = new int[n];

    for(int i=0; i<n; i++)
    {
        ptr[i] = i+1;
    }

    return ptr;
}

int main()
{
    int n;
    cin>>n;

    int *pointer;
    pointer = init(n);

    for(int i=0; i<n; i++)
    {
        cout<<pointer[i]<<" ";
    }

    

    cout<<endl;
    return 0;
}