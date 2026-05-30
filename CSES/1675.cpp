#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m;
struct edge
{
    ll u, v, w;
    bool operator<(const edge &other) const
    {
        return w < other.w;
    }
};
vector<edge> g;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

    }
    return 0;
}