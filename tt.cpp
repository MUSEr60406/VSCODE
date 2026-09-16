#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定義邊的結構，比起二維陣列或鄰接串列，線性走訪更有效率
struct Edge {
    int u, v;
    long long w;
};

int main() {
    // 優化輸入輸出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // dis 陣列初始為 0，等同於一個超級源點連接所有節點，能完美處理非連通圖
    vector<long long> dis(n + 1, 0);
    vector<int> parent(n + 1, -1);
    int x = -1;

    // Bellman-Ford 演算法
    // 總共執行 n 次。前 n-1 次為正常鬆弛，第 n 次用來檢測負環
    for (int i = 0; i < n; ++i) {
        x = -1;
        for (const auto& e : edges) {
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v; // 記錄最後一次被更新的節點
            }
        }
    }

    // 如果第 n 次沒有發生任何更新，代表沒有負環
    if (x == -1) {
        cout << "NO\n";
    } else {
        // x 不一定在負環上，可能只是受到負環影響。
        // 沿著 parent 往回走 n 次，確保最終停留的節點絕對在負環內。
        for (int i = 0; i < n; ++i) {
            x = parent[x];
        }

        vector<int> cycle;
        // 開始收集負環節點
        for (int v = x;; v = parent[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1) {
                break;
            }
        }

        // 因為是往回追溯，順序是反的，需要反轉
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}