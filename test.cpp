#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, ans = 0, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    cin >> n >> m;
    vector<string> M(n);
    for(int i = 0 ; i < n ; i++)
        cin >> M[i];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(M[i][j] == '#')
                continue;
            ans++;
            queue<pll> q;
            q.push({i, j});
            while(!q.empty())
            {
                auto [x, y] = q.front();
                q.pop();
                for(int k = 0 ; k < 4 ; k++)
                {
                    ll nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || M[nx][ny] == '#')
                        continue;
                    q.push({nx, ny});
                    M[nx][ny] = '#';
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}