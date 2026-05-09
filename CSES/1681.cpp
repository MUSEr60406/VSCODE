#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> deg;
vector<int> dp;
void bfs()
{
    queue<int> q;
    for(int i = 1 ; i <= n ; i++)
    {
        if(deg[i] == 0)
            q.push(i);
    }   
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int &v : g[u])
        {
            if(dp[u] > 0)
                dp[v] = (dp[u] + dp[v]) % ((int)1e9 + 7);
            deg[v]--;
            if(deg[v] == 0)
                q.push(v);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    g.resize(n + 1);
    deg.assign(n + 1, 0);
    dp.assign(n + 1, 0);
    dp[1] = 1;
    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        deg[b]++;
    }
    bfs();
    cout << dp[n];
    return 0;
}