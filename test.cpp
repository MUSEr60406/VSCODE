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
    vector<ll> dis(n + 1, 0); // 初
    vector<ll> fa(n + 1, 0);
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        M[u].push_back({v, w});
    }
    ll x = -1; 
    for(ll i = 0 ; i < n ; i++)
    {
        x = -1; 
        for(ll u = 1 ; u <= n ; u++)
        {
            for(auto &[v, w] : M[u])
            {
                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    fa[v] = u;
                    x = v; 
                }
            }
        }
    }
    if(x == -1)
        cout << "NO\n";
    else
    {
        for(ll i = 0 ; i < n ; i++)
            x = fa[x];
        vector<ll> cycle;
        ll curr = x;
        while(true)
        {
            cycle.push_back(curr);
            curr = fa[curr];
            if(curr == x && cycle.size() > 1) 
            {
                cycle.push_back(curr);
                break;
            }
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES\n";
        for(ll &node : cycle)
        {
            cout << node << " ";
        }
        cout << "\n";
    }
    
    return 0;
}