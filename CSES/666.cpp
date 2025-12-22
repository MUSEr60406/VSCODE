#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> g, gr; // g: 正向圖, gr: 反向圖
vector<bool> visited;
vector<int> order, comp;

void dfs1(int u) {
    visited[u] = true;
    for(int v : g[u]) {
        if(!visited[v]) dfs1(v);
    }
    order.push_back(u); // 完成時間順序
}

void dfs2(int u, int label) {
    visited[u] = true;
    comp[u] = label;
    for(int v : gr[u]) {
        if(!visited[v]) dfs2(v, label);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    g.assign(n+1, vector<int>());
    gr.assign(n+1, vector<int>());
    visited.assign(n+1, false);
    comp.assign(n+1, 0);

    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a); // 反向圖
    }

    // 第一次 DFS 記錄完成時間
    for(int i=1;i<=n;i++){
        if(!visited[i]) dfs1(i);
    }

    fill(visited.begin(), visited.end(), false);
    int scc_count = 0;

    // 第二次 DFS 按完成時間逆序在反向圖上找 SCC
    for(int i=n-1;i>=0;i--){
        int u = order[i];
        if(!visited[u]){
            scc_count++;
            dfs2(u, scc_count);
        }
    }

    cout << scc_count << "\n";
    for(int i=1;i<=n;i++) cout << comp[i] << " ";
    cout << "\n";

    return 0;
}
