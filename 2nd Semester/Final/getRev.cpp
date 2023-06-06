#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string nm;
    int cls;
    char s;
    int math_marks;
    int eng_marks;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    student s[n];

    for(int i=0; i<n; i++)
    {
        cin>>s[i].nm>>s[i].cls>>s[i].s>>s[i].math_marks>>s[i].eng_marks;
        cin.ignore();
    }

    for(int i=n-1; i>=0; i--)
    {
        cout<<s[i].nm<<" "<<s[i].cls<<" "<<s[i].s<<" "<<s[i].math_marks<<" "<<s[i].eng_marks<<endl;
    }

}
