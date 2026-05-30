#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll n, m, ans = 0, used = 0;
struct edge
{
    ll u, v, w;
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};
vector<edge> g;
vector<ll> par;
ll find(ll x)
{
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]);
}
void kruskal()
{
    sort(g.begin(), g.end());
    for(int i = 1 ; i <= n ; i++)
        par[i] = i;
    for(edge &e : g)
    {
        ll x = find(e.u), y = find(e.v);
        if(x != y)
        {
            par[x] = y;
            ans += e.w;
            used++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    par.resize(n + 1);
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        g.push_back({a, b, c});
    }
    kruskal();
    if(used == n - 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
    cout << "\n";
    return 0;
}