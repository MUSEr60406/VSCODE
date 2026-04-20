#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int c, n, m, INF = INT_MAX / 2;
vector<vector<pii>> g;
vector<int> d;
bool f()
{
    for(int i = 0 ; i <= n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            for(auto &[v, w] : g[j])
            {
                if(d[j] + w < d[v])
                {
                    if(i == n)
                        return true;
                    d[v] = d[j] + w;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> c;
    while(c--)
    {
        cin >> n >> m;
        g.clear();
        g.resize(n);
        d.assign(n, INF);
        for(int i = 0 ; i < m ; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        cout << (f() ? "possible" : "not possible");
        if(n)
            cout << "\n";
    }
    return 0;
}