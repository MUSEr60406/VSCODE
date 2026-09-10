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
        cin >> u >> v >> w;
        M[u].push_back({w, v});
    }
    dis[1] = 0;
    for(int ii = 1 ; ii <= n - 1 ; ii++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(auto &[w, v] : M[i])
            {
                if(dis[i] > -LLONG_MAX / 2)
                {
                    if(dis[i] + w > dis[v])
                        dis[v] = dis[i] + w;
                }   
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(auto &[w, v] : M[i])
        {
            if(dis[i] <= -LLONG_MAX / 2)
                continue;
            if(dis[i] >= LLONG_MAX / 2 || dis[i] + w > dis[v])
                dis[v] = LLONG_MAX / 2;
        }
    }
    cout << (dis[n] >= LLONG_MAX / 2 ? -1 : dis[n]) << "\n";
    return 0;
}