#include <bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define ll long long
using namespace std;

// 定義狀態：{當前總花費, {當前節點, 是否已使用過優惠券}}
struct State {
    ll d;
    int u;
    int used;
    bool operator>(const State& other) const {
        return d > other.d;
    }
};

int n, m;
vector<vector<pii>> flight;
ll cost[100005][2]; // cost[node][0]: 未用, cost[node][1]: 已用

void dijkstra() {
    // 初始化為極大值
    for(int i = 0; i <= n; i++) {
        cost[i][0] = cost[i][1] = LLONG_MAX;
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    
    cost[1][0] = 0;
    pq.push({0, 1, 0});

    while(!pq.empty()) {
        State cur = pq.top();
        pq.pop();

        ll d = cur.d;
        int u = cur.u;
        int used = cur.used;

        if(d > cost[u][used]) continue;

        for(auto &edge : flight[u]) {
            int v = edge.first;
            int w = edge.second;

            // 1. 不管有沒有用過優惠券，這一段都直接買原價
            if(cost[v][used] > d + w) {
                cost[v][used] = d + w;
                pq.push({cost[v][used], v, used});
            }

            // 2. 如果目前還沒用過優惠券，這一段嘗試使用優惠券
            if(used == 0) {
                if(cost[v][1] > d + (w / 2)) {
                    cost[v][1] = d + (w / 2);
                    pq.push({cost[v][1], v, 1});
                }
            }
        }
    }
    cout << cost[n][1] << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    if (!(cin >> n >> m)) return 0;
    flight.resize(n + 1);
    for(int i = 0 ; i < m ; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        flight[a].push_back({b, c});
    }
    dijkstra();
    return 0;
}