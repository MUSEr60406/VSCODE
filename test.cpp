#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll n, m;
vector<vector<ll>> M(n + 1);
vector<bool> vis(n + 1);
vector<bool> stack(n + 1, false);
vector<ll> path, cycle;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v;
        cin >> u >> v;
        M[u].push_back(v);
    }
    bool c = false;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {

        }
    }

    return 0;
}