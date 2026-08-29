#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    vector<vector<ll>> M(n + 1);
    vector<bool> vis(n + 1, false);
    vector<ll> fa(n + 1);
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    queue<ll> q;
    q.push(1);
    vis[1] = true;
    while(!q.empty())
    {
        ll now = q.front();
        q.pop();
        for(ll &v : M[now])
        {
            if(!vis[v])
            {
                fa[v] = now;
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return 0;
}