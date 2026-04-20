#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m, INF = INT_MAX / 2;
vector<vector<pii>> g;
vector<int> d;
bool f()
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    while(n--)
    {
        cin >> m;
        g.clear();
        g.resize(m);
        d.assign(m, INF);
        for(int i = 0 ; i < m ; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }
        cout << (f() ? "possible" : "impossible") << (n ? "\n" : "");
    }

    return 0;
}