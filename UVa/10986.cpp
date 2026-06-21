#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m, s, t;
vector<vector<pii>> g;
vector<int> dis;
void dijkstra()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while(!pq.empty())
    {
        auto [d, curr] = pq.top();
        pq.pop();
        if(d > dis[curr])
            continue;
        for(auto &[v, w] : g[curr])
        {
            if(dis[curr] + w < dis[v])
            {
                dis[v] = dis[curr] + w;
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
        cin >> n >> m >> s >> t;
        g.clear();
        dis.clear();
        dis.assign(n, 1e8);
        for(int i = 0 ; i < m ; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        cout << "Case #" << c << ": ";
        dijkstra();
        if(dis[t] == 1e9)
            cout << "unreachble\n";
        else
            cout << dis[t];
    }

    return 0;
}