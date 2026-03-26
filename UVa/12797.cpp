#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int N;
vector<string> g;
vector<vector<int>> dis;
unordered_map<int, char> um;
void bfs()
{
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    queue<pii> q;
    q.push({0, 0});
    dis[0][0] = 0;
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if(newx < 0 || newx >= N || newy < 0 || newy >= N || dis[newx][newy] != -1 || um[tolower(g[newx][newy]) - 'a'] != g[newx][newy])
                continue;
            um[tolower(g[newx][newy] - 'a')] = g[newx][newy];
            dis[newx][newy] = dis[x][y] + 1;
            q.push({newx, newy});
        }
    }
    cout << dis[N - 1][N - 1] << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin >> N)
    {
        um.clear();
        g.clear();
        g.resize(N);
        dis.assign(N, vector<int>(N, -1));
        for(auto &s : g)
            cin >> s;
        bfs();
    }

    return 0;
}