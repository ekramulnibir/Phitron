#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int num[n];

        for(int i=0; i<n; i++) cin>>num[i];
        sort(num,num+n);

        pair<int, int> pr;

        pr = make_pair(0,0);
        int count=1;

        for(int i=0; i<n; i++)
        {
            if(num[i] == num[i+1]) count++;
            else count = 1;

            if(count>pr.second)
            {
                pr.first = num[i];
                pr.second = count;
            }
            else if(count>=pr.second && num[i]>pr.first)
            {
                pr.first = num[i];
                pr.second = count;
            }
        }

        cout<<pr.first<<" "<<pr.second<<endl;
    
    }
    
    return 0;
}