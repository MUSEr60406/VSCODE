#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN], timer;
bool inStack[MAXN];
stack<int> st;
int sccCount = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (!dfn[v]) { // 未訪問過
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) { // 已在堆疊中，是一條回邊
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) { // 找到一個 SCC
        sccCount++;
        while (true) {
            int node = st.top();
            st.pop();
            inStack[node] = false;
            // 這裡可以記錄 node 屬於哪個 sccCount
            if (u == node) break;
        }
    }
}