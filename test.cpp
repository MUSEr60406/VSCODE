#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll n, m, q;
vector<vector<pll>> M(505, vector<pll>(505));
vector<ll> vis(505);
void dij(ll start, ll end)
{
    vis.assign(505, LLONG_MAX/2);
    vis[start] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, start});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > vis[u]) 
            continue;
        for(auto &[w, v] : M[u])
        {
            if(vis[u] + w < vis[v])
            {
                vis[v] = vis[u] + w;
                pq.push({vis[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        M[u].push_back({w, v});
        M[v].push_back({w, u});
    }
    for(ll i = 0 ; i < q ; i++)
    {
        ll start, end;
        cin >> start >> end;
    }

    return 0;
}