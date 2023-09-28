#include<bits/stdc++.h>
using namespace std;

int binary(int n, int ar[], int element) {
    int idx = -1;
    int left = 0;
    int right = n - 1;

    while(left<=right) {
        int mid = (left + right) / 2;

        if (ar[mid] == element) {
            idx = mid;
            return idx;
        } 
        else if (ar[mid] < element) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }

    return idx;
}

int main() {
    int n;
    cin>>n;

    int ar[n];
    for(int i = 0; i < n; i++) cin >> ar[i];

    int ele;
    cin >> ele;

    
    if(binary(n, ar, ele) != -1){
        cout <<binary(n, ar, ele)<<endl;
    } else {
        cout<<"Not Found"<<endl;
    }

    return 0;
}
