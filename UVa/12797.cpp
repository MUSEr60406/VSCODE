#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define INF 1e9
using namespace std;
int N;
vector<string> g;
vector<vector<int>> dis;
bool check(char c, int p)
{
    int id  = tolower(c) - 'a';
    return (bool)isupper(c) == (bool)((p >> id) & 1);
}
int bfs(int p)
{
    if(!check(g[0][0], p))
        return INF;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    dis.assign(N, vector<int>(N, -1));
    queue<pii> q;
    q.push({0, 0});
    dis[0][0] = 1;
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if(newx < 0 || newx >= N || newy < 0 || newy >= N || dis[newx][newy] != -1 || !check(g[newx][newy], p))
                continue;
            dis[newx][newy] = dis[x][y] + 1;
            q.push({newx, newy});
        }
    }
    return (dis[N - 1][N - 1] == -1 ? INF : dis[N - 1][N - 1]);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin >> N)
    {
        int ans = INF;
        g.clear();
        g.resize(N);
        for(auto &s : g)
            cin >> s;
        for(int i = 0 ; i < 1024 ; i++)
            ans = min(ans, bfs(i));
        cout << (ans == INF ? -1 : ans) << "\n";
    }
    return 0;
}