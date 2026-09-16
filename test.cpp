#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    cin >> n >> m;
    vector<vector<pll>> M(n + 1);
    vector<ll> dis(n + 1, 0);
    vector<ll> fa(n + 1, 0);
    vector<ll> cycle;
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        M[u].push_back({v, w});
    }
    for(ll u = 1 ; u <= n ; u++)
    {
        for(ll i = 0 ; i < n - 1 ; i++)
        {
            for(auto &[v, w] : M[u])
            {
                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    fa[v] = u;
                }
            }
        }
    }
    for(ll u = 1 ; u <= n ; u++)
    {
        for(auto &[v, w] : M[u])
        {
            if(dis[u] + w < dis[v])
            {
                ll node = v, start;
                for(ll i = 0 ; i < n ; i++)
                {
                    start = fa[node];
                    node = start;
                }
                ll now = fa[start];
                cycle.push_back(start);
                while(now != start)
                {
                    cycle.push_back(now);
                    now = fa[now];
                }
                cout << "YES\n";
                for(ll &i : cycle)
                    cout << i << " ";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}