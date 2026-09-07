#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll n, m, q;
ll adj[505][505], ans[505][505];
void dij(ll start)
{
    dis[start][start] = 0;
    vector<ll> dis(n + 1, LLONG_MAX / 2); 
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> q;
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = min(adj[u][v], w);
        adj[v][u] = min(adj[v][u], w);
    }
    for(ll i = 1 ; i <= 500 ; i++)
        dij(i);
    for(ll i = 0 ; i < q ; i++)
    {
        ll start, end;
        cin >> start >> end;
      
    }

    return 0;
}