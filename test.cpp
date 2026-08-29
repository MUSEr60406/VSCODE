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
    vector<vector<ll>> M(n + 1);
    vector<bool> vis(n + 1, false);
    vector<int> cities;
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        M[a].push_back(b);
        M[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            cities.push_back(i);
            vis[i] = true;
            queue<ll> q;
            q.push(i);
            while(!q.empty())
            {
                for(ll &v : M[i])
                {
                    if(!vis[v])
                    {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
    }
    return 0;
}