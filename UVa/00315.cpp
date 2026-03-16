#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int t, scc = 0;
vector<vector<int>> g;
vector<int> d;
vector<int> low;
vector<bool> cut;
void dfs(int u, int p)
{
    d[u] = low[u] = t++;
    int children = 0;
    
    for(int &v : g[u])
    {
        if(d[v] == 0)
        {
            children++;
            dfs(v, u);
            low[u] = min(low[v], low[u]);
        }
    }
    
    
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        string s;
        g.assign(n + 1, vector<int>());
        cin.ignore();
        while(getline(cin, s) && s != "0") 
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while(ss >> v)
            {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        t = 0; //遍歷先後順序
        d.assign(n + 1, 0); //0 = unvisited
        low.assign(n + 1, 0); //low-link
        cut.assign(n + 1, false);
        for(int i = 1 ; i <= n ; i++)
            if(d[i] == 0)
                dfs(i, -1);
    }

    return 0;
}