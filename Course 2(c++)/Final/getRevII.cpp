#include <iostream>
#include <string>
using namespace std;

class student {
public:
    string nm;
    int cls;
    char s;
    int id;
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    student s[n];

    for(int i=0; i<n; i++)
    {
        cin>>s[i].nm>>s[i].cls>>s[i].s>>s[i].id;
        cin.ignore();
    }

    int i = 0, j = n -1, tempId;

    while(i<j)
    {
        tempId = s[i].id;
        s[i].id = s[j].id;
        s[j].id = tempId;
        j--;
        i++;
    }

    for(int i=0; i<n; i++)
    {
        cout<<s[i].nm<<" "<<s[i].cls<<" "<<s[i].s<<" "<<s[i].id<<endl;
    }

}
