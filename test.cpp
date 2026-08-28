#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, ans = 0, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    map<int, char> dir = {{0, 'D'}, {1, 'R'}, {2, 'U'}, {3, 'L'}};
    pii s, e;
    cin >> n >> m;
    vector<vector<char>> M(1000, vector<char>(1000, '#'));
    vector<vector<char>> d(1000, vector<char>(1000));
    vector<vector<int>> p(1000, vector<int>(1000, 0));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> M[i][j];
            if(M[i][j] == 'A')
            {
                s = {i, j};
                M[i][j] = '#';
            }
            if(M[i][j] == 'B')
                e = {i, j};
        }
    }
    queue<pii> q;
    q.push(s);
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || M[nx][ny] == '#')
                continue;
            d[nx][ny] = dir[i];
            p[nx][ny] = p[x][y] + 1;
            M[nx][ny] = '#';
            q.push({nx, ny});
            if(nx == e.first && ny == e.second)
            {
                map<char, pii> DIR = {{'U', {1, 0}}, {'D', {-1, 0}}, {'L', {0,1}}, {'R', {0, -1}}};
                string path = "";
                int X = nx, Y = ny;
                while(!(X == s.first && Y == s.second))
                {
                    path += d[X][Y];
                    X += DIR[d[X][Y]].first, Y += DIR[d[X][Y]].second;
                }
                reverse(path.begin(), path.end());
                path += '\n';
                cout << "YES\n" << p[e.first][e.second] << "\n" << path;
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}