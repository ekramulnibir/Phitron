#include<bits/stdc++.h>
using namespace std;

void merge(int ar[],int l, int mid, int r)
{
    int leftSize = mid - l +1;
    int rightSize = r - mid;
    int L[leftSize], R[rightSize];
    int k = 0;
    for(int i=l; i<=mid; i++)
    {
        L[k] = ar[i];
        k++;
    }
    k = 0;
    for(int i = mid+1; i<=r; i++)
    {
        R[k] = ar[i];
        k++;
    }

    /*  for(int i = 0; i<leftSize; i++)
    {
        cout<<L[i]<<" ";
    }

    cout<<endl;

    for(int i = 0; i<rightSize; i++)
    {
        cout<<R[i]<<" ";
    } */

    

    int i = 0;
    int j = 0;
    int curr = l;

    while(i<leftSize && j<rightSize)
    {
        if(L[i] >= R[j])
        {
            ar[curr] = L[i];
            i++;
        }

        else{
            ar[curr] = R[j];
            j++;
        }

        curr++;
    }

    while (i<leftSize)
    {
        ar[curr] = L[i];
        i++;
        curr++;
    }

    while (j<rightSize)
    {
        ar[curr] = R[j];
        j++;
        curr++;
    }
}

void mergeSort(int ar[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        mergeSort(ar,l,mid);
        mergeSort(ar,mid+1,r);

        merge(ar,l,mid,r);
    }
}


int main()
{
    int n;
    cin>>n;

    int ar[n];
    for(int i=0; i<n; i++) cin>> ar[i];

    int l = 0, r = n-1, mid = (l+r)/2;
    
    mergeSort(ar,l,r);

    for(int i=0; i<n; i++)
    {
        cout<<ar[i]<< " ";
    }

    cout<<endl;
    return 0;
}


