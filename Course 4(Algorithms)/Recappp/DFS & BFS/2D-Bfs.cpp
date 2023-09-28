#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1005;
vector<pii> path = {make_pair(-1,0),make_pair(1,0),make_pair(0,-1),make_pair(0,1)};
int visited[N][N];
int dist[N][N];
int n,m;

bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0  && cj<m) return true;
    return false;
}

void bfs(int si,int sj)
{
    queue<pii> q;
    q.push(make_pair(si,sj));
    dist[si][sj] = 0;
    
    while(!q.empty())
    {
        pii u = q.front();
        int pi = u.first;
        int pj = u.second;
        q.pop();
        visited[pi][pj] = true;

        for(int i=0; i<4; i++)
        {
            pii pth = path[i];
            int ci = pi + pth.first;
            int cj = pj + pth.second;

            if(isValid(ci,cj) && !visited[ci][cj])
            {
                q.push(make_pair(ci,cj));
                dist[ci][cj] = dist[pi][pj]+1;
            }
        }


    }
     
}

int main()
{
    cin>>n>>m;
    char grid[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    int si,sj;
    cin>>si>>sj;

    bfs(si,sj);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    return 0;
}