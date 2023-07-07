#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string nm;
    int cls;
    char s;
    int id;
    int math_marks;
    int eng_marks;
};

bool compareID(student a,student b)
{
    if(a.id < b.id) return true;
    
    return false;
}

bool compare(student a,student b)
{
    int aTotal = a.math_marks + a.eng_marks;
    int bTotal = b.math_marks + b.eng_marks;

    if(aTotal > bTotal) return true; 
    else if(aTotal == bTotal) return compareID(a,b);

    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    student s[n];

    for(int i=0; i<n; i++)
    {
        cin>>s[i].nm>>s[i].cls>>s[i].s>>s[i].id>>s[i].math_marks>>s[i].eng_marks;
        cin.ignore();
    }

    sort(s, s+n, compare);

    for(int i=0; i<n; i++)
    {
        cout<<s[i].nm<<" "<<s[i].cls<<" "<<s[i].s<<" "<<s[i].id<<" "<<s[i].math_marks<<" "<<s[i].eng_marks<<endl;
    }


}
