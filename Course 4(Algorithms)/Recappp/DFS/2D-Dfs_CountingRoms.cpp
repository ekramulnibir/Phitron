#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m;
const int N = 1005;
bool visited[N][N];
char grid[N][N];
//vector<pii> path = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
vector<pii> path = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int cI, int cJ)
{
    if(cI>=0 && cI<n && cJ>=0 && cJ<m && grid[cI][cJ]=='.') return true;
    return false;

}
void dfs(int si, int sj)
{
    visited[si][sj] = true;
    for(int i=0; i<4; i++)
    {
        pii parent = path[i];
        int cI = si + parent.first;
        int cJ = sj + parent.second;

        if(isValid(cI,cJ) && !visited[cI][cJ])
        {
            dfs(cI,cJ);
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
            cin>>grid[i][j];
        }
    }

    int cc = 0;


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(!visited[i][j] && grid[i][j]=='.')
            {
                dfs(i,j);
                cc++;
            }
        }
    }


    cout<<cc<<endl;
    return 0;
}