#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, ans = 0, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    map<int, char> dir = {{0, 'U'}, {1, 'L'}, {2, 'D'}, {3, 'R'}};
    pii s, e;
    cin >> n >> m;
    vector<vector<char>> M(1000, vector<char>(1000, '#'));
    vector<vector<int>> d(1000, vector<int>(1000));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> M[i][j];
            if(M[i][j] == 'A')
                s = {i, j};
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
        }
    }

    return 0;
}