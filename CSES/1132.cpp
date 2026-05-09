#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int n;
vector<vector<int>> tree;
vector<int> dis;
vector<int> a;
vector<int> b;
pair<vector<int>, int> bfs(int start)
{
    int deepest_node = start, max = 0;
    dis.assign(n + 1, -1);
    queue<int> q;
    q.push(start);
    dis[start] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int &v : tree[u])
        {
            if(dis[v] != -1) 
                continue;
            dis[v] = dis[u] + 1;
            q.push(v);
            if(dis[v] > max)
            {
                deepest_node = v;
                max = dis[v];
            }
        }
    }
    return {dis, deepest_node};
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    tree.resize(n + 1);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto[d, A] = bfs(1);
    auto[d, B] = bfs(A);
    a = d;
    auto[d, X] = bfs(B);
    b = d;
    for(int i = 1 ; i <= n ; i++)
        cout << max(a[i], b[i]) << (i == n ? "" : " ");
    return 0;
}