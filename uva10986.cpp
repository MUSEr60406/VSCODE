#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m, S, T;
vector<vector<pii>> g;
vector<int> dis;
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[S] = 0;
    pq.push({dis[S], S});
    while(!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if(d > dis[u])
            continue;
        for(auto &[v, w] : g[u])
        {
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c;
    cin >> c;
    for(int i = 1 ; i <= c ; i++)
    {
        cin >> n >> m >> S >> T;
        g.clear();
        dis.clear();
        g.resize(n);
        dis.assign(n, 1e8);
        for(int j = 0 ; j < m ; j++)
        {
            int u, v, w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
    }
    dijkstra();
    if(dis[T] == 1e8)
        cout << "unreachable\n";
    else
        cout << dis[T] << "\n";

    return 0;
}