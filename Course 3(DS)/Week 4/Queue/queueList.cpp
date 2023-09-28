#include<bits/stdc++.h>
using namespace std;

class myQueue
{
    public:
    list<int> l;

    void push(int val){
       l.push_back(val);
    }

    void pop()
    {
       l.pop_front();
    }

    int front()
    {
        l.front();
    }

    int size()
    {
        l.size();
    }

    bool empty()
    {
        l.empty();
    }


};

int main()
{
    

    cout<<endl;
    return 0;
}