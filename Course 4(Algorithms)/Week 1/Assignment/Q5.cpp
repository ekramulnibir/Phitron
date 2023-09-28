#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arx[n];

    for(int i=0; i<n; i++) cin>>arx[i];

    int m;
    cin>>m;
    int ary[m];

    for(int i=0; i<m; i++) cin>>ary[i];

    int newAr[n+m];
    int x = 0;
    int y = 0;

    for(int i=0; i<n+m; i++)
    {
        if(arx[x]>ary[y])
        {
            newAr[i] = arx[x];
            x++;
        }
        else{
            newAr[i] = ary[y];
            y++;
        }
        
    }

    for(int i=0; i<n+m; i++) cout<<newAr[i]<<" ";


    cout<<endl;
    return 0;
}