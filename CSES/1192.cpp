//Counting Room
#include<iostream>
#include<vector>
#include<queue>
#define pii pair<int,int>
using namespace std;
int m, n;
void bfs(vector<string> &MAP, vector<vector<bool>> &visited, int now_x, int now_y)
{
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    queue<pii> q; 
    q.push({now_x,now_y});
    visited[now_x][now_y] = true;
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = p.first + dx[i], newy = p.second + dy[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= m || visited[newx][newy] || MAP[newx][newy] == '#')
                continue;
            else
            {
                visited[newx][newy] = true;
                q.push({newx,newy});
            }
        }
    }
}
int main()
{
    int ans = 0;
    cin >> n >> m;
    vector<string> MAP(n);
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    for(int i = 0 ; i < n ; i++)
        cin >> MAP[i];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(MAP[i][j] == '.' && !visited[i][j])
            {
                ans++;
                bfs(MAP,visited,i,j);
            }
        }
    }
    cout << ans;
    return 0;   
}