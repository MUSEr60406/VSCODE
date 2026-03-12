#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> edge(n + 1, vector<int>());
    vector<int> dis(n + 1, -1);
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int parent, child;
        cin >> parent >> child;
        edge[parent].push_back(child);
        edge[child].push_back(parent);
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int &v : edge[now])
        {
            if(dis[v] != -1)
                continue;
            dis[v] = dis[now] + 1;
            q.push(v);
        }
    }

    int u, max = -1;
    for(int i = 1 ; i <= 5 ; i++)
        if(dis[i] > max)
            u = i;

    dis.assign(n + 1, -1);
    q.push(u);
    dis[u] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int &v : edge[now])
        {
            if(dis[v] != -1)
                continue;
            dis[v] = dis[now] + 1;
            q.push(v);
        }
    }

    int ans = -1;
    for(int &d : dis)
        if(d > ans)
            ans = d;
    
    cout << ans << "\n";

    return 0;
}