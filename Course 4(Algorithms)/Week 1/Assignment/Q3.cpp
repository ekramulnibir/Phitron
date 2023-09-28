#include<bits/stdc++.h>
using namespace std;

int binary(int n, int ar[], int element)
{
    int count = 0;
    int left = 0;
    int right = n - 1;

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(ar[mid] == element)
        {
            if(ar[mid-1] == element || ar[mid+1] == element)
            {
                count++;
                return count;
            }

            return count;
        }
        else if(ar[mid] <= element)
        {
            left = mid +1;
        }
        else{
            right = mid - 1;
        }
    }

    return count;
}

int main()
{
    int n;
    cin>>n;

    int ar[n];
    for(int i=0; i<n; i++) cin>>ar[i];

    int ele;
    cin>>ele;

    if(binary(n, ar, ele)>0)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}
