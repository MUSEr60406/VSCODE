#include<iostream>
#include<queue>
#include<vector>
#define pii pair<int,int>
using namespace std;
int m, n, dx[] = {1,0,-1,0,1,1,-1,-1}, dy[] = {0,1,0,-1,1,-1,1,-1};
void bfs(int x, int y, vector<string> &MAP, vector<vector<bool>> &visited)
{
    queue<pii> q;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        for(int i = 0 ; i < 8 ; i++)
        {
            int newx = p.first + dx[i], newy = p.second + dy[i];
            
            if(newx < 0 || newy < 0 || newx >= m || newy >= n || MAP[newx][newy] == '*' || visited[newx][newy])
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
    while(cin >> m >> n && m != 0 && n != 0)
    {
        int ans = 0;
        vector<string> MAP(m);
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for(int i = 0 ; i < m ; i++)
            cin >> MAP[i];
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(visited[i][j] == false && MAP[i][j] == '@')
                {
                    bfs(i,j,MAP,visited);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}