#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll n, m;
vector<vector<ll>> M;
vector<bool> vis;
vector<bool> Stack;
vector<ll> path, cycle;
bool dfs(ll start)
{
    vis[start] = true;
    Stack[start] = true;
    path.push_back(start);
    for(ll &v : M[start])
    {
        if(!vis[v])
        {
            if(dfs(v))
                return true;
        }
        else if(Stack[v])
        {
            auto it = find(path.begin(), path.end(), v);
            cycle.assign(it, path.end());
            return true;
        }
    }
    Stack[start] = false;
    path.pop_back();
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    M.resize(n + 1);
    vis.assign(n + 1, false);
    Stack.assign(n + 1, false);
    for(ll i = 0 ; i < m ; i++)
    {
        ll u, v;
        cin >> u >> v;
        M[u].push_back(v);
    }
    bool c = false;
    for(ll i = 1 ; i <= n ; i++)
    {
        if(!vis[i])
        {
            if(dfs(i))
            {
                c = true;
                break;
            }
        }
    }
    if(c)
    {
        cout << cycle.size() + 1 << "\n";
        for(ll &node : cycle)
            cout << node << " ";
        cout << *cycle.begin() << "\n";
    }
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}