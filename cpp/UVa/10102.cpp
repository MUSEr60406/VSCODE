#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    while(cin >> n)
    {
        int ans = 0;
        vector<vector<int>> color(n, vector<int> (n, 0)), path(n, vector<int>(n, -1));
        vector<pii> start;
        for(int i = 0 ; i < n ; i++)
        {
            string s;
            cin >> s;
            for(int j = 0 ; j < s.size() ; j++)
            {
                color[i][j] = s[j] - '0';
                if(color[i][j] == 1)
                    start.push_back({i,j});
            }
        }
        for(int i = 0 ; i < start.size() ; i++)
        {
            path.assign(n, vector<int>(n, -1));
            queue<pii> q; // bfs
            q.push(start[i]);
            path[start[i].first][start[i].second] = 0;
            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                if(color[x][y] == 3)
                {
                    ans = max(ans, path[x][y]);
                    break;
                }
                for(int i = 0 ; i < 4 ; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n || path[nx][ny] != -1)
                        continue;
                    path[nx][ny] = path[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}