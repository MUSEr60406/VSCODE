#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n, m;
vector<vector<pii>> flight;
ll cost[100005][2];
void dijkstra()
{
    for(int i = 1 ; i <= n ; i++)
        cost[i][0] = cost[i][1] = LLONG_MAX / 2;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    cost[1][0] = 0;
    pq.push({0, 1, 0});
    while(!pq.empty())
    {
        auto [d, node, coupon] = pq.top();
        pq.pop();
        if(d > cost[node][coupon])
            continue;
        for(auto &[v, w] : flight[node])
        {
            if(cost[v][coupon] > d + w)
            {
                cost[v][coupon] = d + w;
                pq.push({cost[v][coupon], v, coupon});
            }
            if(coupon == 0)
            {
                if(cost[v][1] > d + w / 2)
                {
                    cost[v][1] = d + w / 2;
                    pq.push({cost[v][1], v, 1});
                }
            }
        }
    }
    cout << cost[n][1] << "\n";
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    flight.resize(n + 1);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        flight[a].push_back({b, c});
    }
    dijkstra();

    return 0;
}