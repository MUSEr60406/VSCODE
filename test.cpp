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
    vector<vector<ll>> fri(n + 1);
    vector<int> team(n + 1, 1);
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        fri[a].push_back(b);
        fri[b].push_back(a);
    }
    queue<ll> q;
    q.push(1);


    return 0;
}