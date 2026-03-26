#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m, last_node;
    cin >> n >> m;
    vector<vector<pll>> MAP(n + 1);
    vector<ll> dis(n + 1, 0);
    vector<ll> parent(n + 1, -1);
    for(ll i = 0 ; i < m ; i++)
    {
        ll a, b, w;
        cin >> a >> b >> w;
        MAP[a].push_back({b, w});
    }
    for(ll k = 0 ; k < n ; k++)
    {
        last_node = -1;
        for(ll i = 1 ; i <= n ; i++)
        {
            for(auto &[v, w] : MAP[i])
            {
                if(dis[i] + w < dis[v])
                {
                    dis[v] = dis[i] + w;       
                    parent[v] = i;
                    last_node = v;
                }    
            }
        }
    }
    if(last_node == -1)
        cout << "NO\n";
    else
    {
        cout << "YES\n";
        ll curr = last_node;
        for(ll i = 0 ; i < n ; i++)
            curr = parent[curr];
        //
        vector<ll> cycle;
        ll temp = curr;
        while(true)
        {
            cycle.push_back(temp);
            if(curr == temp && cycle.size() > 1)
                break;
            temp = parent[temp];
        }
        for(ll i = cycle.size() - 1 ; i >= 0 ; i--)
            cout << cycle[i] << " ";
    }
    return 0;
}