#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<ll>> M(505, {505, LLONG_MAX / 2});
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, q;
    cin >> n >> m >> q;
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        M[u][v] = M[v][u] = min(M[u][v], w);
    }
    for(ll k = 1 ; k <= n ; k++)
        for(ll i = 1 ; i <= n ; i++)
            for(ll j = 1 ; j <= n ; j++)
                M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
    for(ll i = 0 ; i < q ; i++)
    {
        ll u, v;
        cin >> u >> v;
        if(M[u][v] >= LLONG_MAX / 2)
            cout << "-1\n";
        else
            cout << M[u][v] << "\n";
    }
    return 0;
}