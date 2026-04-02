#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m;
vector<vector<pii>> flight;
vector<int> cost;
void dijkstra()
{
    ll max = -1;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if(d > cost[node])
            continue;
        for(auto &[v, w] : flight[node])
        {
            if(cost[v] > d + w)
            {
                if(w > max)
                    max = w;
                cost[v] = d + w;
                pq.push({cost[v], v});
            }
        }
    }
    cout << cost[n] - max / 2 << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    flight.resize(n + 1);
    cost.assign(n + 1, LLONG_MAX / 2);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        flight[a].push_back({b, c});
    }
    dijkstra();

    return 0;
}