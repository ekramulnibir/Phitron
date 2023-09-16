#include<bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int n,m;
const int N = 1005;
char ar[N][N];
bool visited[N][N];
vector <int> compCount;
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && ar[cI][cJ] == '.') return true;
    return false;
}

void dfs(int sI,int sJ, int &count)
{
    visited[sI][sJ] = true;
    count++;
    
    for(int i=0; i<4; i++)
    {
        pi p = path[i];
        int ci = p.first + sI;
        int cj = p.second + sJ;
        
        if (isValid(ci, cj) && !visited[ci][cj])
        {
            dfs(ci, cj, count);
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



    int cnt = 0;
    int minCount = INT_MAX;
    int compCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && ar[i][j] == '.')
            {
                cnt++;
                dfs(i, j, compCount);
            }
            if(compCount != 0 && minCount>compCount)
            {
                minCount = compCount;
            }
            compCount = 0;
        }
    }
    
    if(minCount != INT_MAX) cout<<minCount<<endl;
    else cout<<-1<<endl;
    
   
    

    cout<<endl;
    return 0;
}