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
    for(int i = 1 ; i < 26 ; i++)
        up[curr][i] = up[up[curr][i - 1]][i - 1];
    for(int &v : tree[curr])
        if(v != par)
            dfs(v, par, depth[curr] + 1);
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
        dfs(root, root, 0); 
        
    }

    return 0;
}