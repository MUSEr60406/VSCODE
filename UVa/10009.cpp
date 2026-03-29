//LCA + 倍增表
#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<int> depth;
vector<vector<int>> up(26, vector<int>(5));
void dfs(int curr, int par, int d)
{
    depth[curr] = d;
    up[curr][0] = par;
    for(int i = 1 ; i < 5 ; i++)
        up[curr][i] = up[up[curr][i - 1]][i - 1];
    for(int &v : tree[curr])
        if(v != par)
            dfs(v, curr, depth[curr] + 1);
}
int LCA(int u, int v)
{
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i = 4 ; i >= 0 ; i--)
    {
        if(depth[up[u][i]] >= depth[v])
            u = up[u][i];
    }
    if(u == v)  //代表u是v的子節點
        return u;
    for(int i = 4 ; i >= 0 ; i--)
    {
        if(up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        tree.clear();
        tree.resize(26);
        depth.clear();
        depth.resize(26);
        up.assign(26, vector<int>(5, 0));
        //
        int m, n, root;
        cin >> m >> n;
        for(int i = 0 ; i < m ; i++)
        {
            string a, b;
            cin >> a >> b;
            tree[a[0] - 'A'].push_back(b[0] - 'A');
            tree[b[0] - 'A'].push_back(a[0] - 'A');
            if(a == "Rome")
                root = 'R' - 'A';
        }
        dfs(root, root, 0); //預處理
        //
        for(int i = 0 ; i < n ; i++)
        {
            string a, b;
            cin >> a >> b;
            int lca = LCA(a[0] - 'A', b[0] - 'A');
            //
            string p1 = "", p2 = "";
            int curr = a[0] - 'A';
            while(curr != lca)
            {
                p1 += curr + 'A';
                curr = up[curr][0];
            }
            curr = b[0] - 'A';
            while(curr != lca)
            {
                p2 += curr + 'A';
                curr = up[curr][0];
            }
            reverse(p2.begin(), p2.end());
            string ans = p1 + (char)(lca + 'A') + p2;
            cout << ans << "\n";
        }
        if(t)
            cout << "\n";
    }

    return 0;
}