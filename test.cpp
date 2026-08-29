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
    vector<vector<ll>> road(n + 1);
    vector<bool> vis(n + 1, false);
    vector<ll> fa(n + 1);
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }

    return 0;
}