#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int n, m, si, sj,di ,dj,flag = 0;
const int N = 1005;
bool vis[N][N];
char a[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
        return true;
    else
        return false;
}
void dfs(int si, int sj)
{
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if(ci == di && cj == dj)
        {
            flag = 1;
        }
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            cout<<"Calling dfs from: "<<ci<<" "<<cj<<endl;
            dfs(ci, cj);
        }
    }
    
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    
    cin>>si>>sj>>di>>dj;
    
    dfs(si,sj);
    
    cout<<flag<<endl;
    

    return 0;
}