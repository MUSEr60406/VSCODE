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
    for(ll i = 0 ; i < n - 1 ; i++)
    {
        for(ll j = 1 ; j <= n ; j++)
        {
            for(auto &[v, w] : M[j])
            {
                if(dis[j] + w < dis[v])
                {
                    dis[v] = dis[j] + w;
                    fa[v] = j;
                }
            }
        }
    }

    return 0;
}