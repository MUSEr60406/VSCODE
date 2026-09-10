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
    vector<ll> dis(n + 1, -LLONG_MAX / 2);
    for(int i = 0 ; i < m ; i++)
    {   
        ll u, v, w;
        cin >> u >> w >> v;
        M[u].push_back({w, v});
        M[w].push_back({w, u});
    }
    dis[1] = 0;
    return 0;
}