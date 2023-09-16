#include<bits/stdc++.h>
using namespace std;

class student
{
    public:
        string name;
        int roll;
        int marks;
    student(string name, int roll, int marks)
    {
        this->marks = marks;
        this->roll = roll;
        this->name = name;
    }
};

class compare
{
    public:
        bool operator()(student a, student b)
        {
            if (a.marks > b.marks)
                return false;
            else if (a.marks < b.marks)
                return true;
            else
            {
                if (a.roll > b.roll)
                    return true;
                else
                    return false;
            }
        }
};

int main()
{
    int n;
    cin>>n;

    priority_queue<student,vector<student>,compare> pq;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        student obj(name, roll, marks);
        pq.push(obj);
    }

    int q;
    cin>>q;
    while(q--)
    {
        int command; cin>>command;
        if(command == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            student obj(name, roll, marks);
            pq.push(obj);
            cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
        }

        else if(command == 1)
        {
            if(!pq.empty()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
            else cout<<"Empty"<<endl;
        }

        else{
            if(!pq.empty()) pq.pop();
            if(!pq.empty()) cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
            else cout<<"Empty"<<endl;
        }
    }
    
    cout<<endl;
    return 0;
}