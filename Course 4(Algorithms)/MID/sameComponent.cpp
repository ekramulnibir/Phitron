#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int n,m,flag = 0;
int si,sj,di,dj;
const int N = 1005;
char ar[N][N];
bool visited[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && ar[cI][cJ] == '.') return true;
    return false;
}

void dfs(int sI,int sJ)
{
    visited[sI][sJ] = true;
    for(int i=0; i<4; i++)
    {
        pi p = path[i];
        int ci = p.first + sI;
        int cj = p.second + sJ;
        
        if(ci == di && cj == dj) flag = 1;
        
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj);
        }
    }

}

int main()
{
    cin>>n>>m;
    

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>ar[i][j];
        }
    }

    cin>>si>>sj>>di>>dj;

    dfs(si,sj);

    if(flag!=0) cout<<"YES\n";
    else cout<<"NO\n";
    

    cout<<endl;
    return 0;
}