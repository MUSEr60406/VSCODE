#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    const ll INF = 1e18;
    cin >> n >> m;
    vector<vector<pll>> Map(n + 1);
    vector<ll> dis(n + 1, INF);
    queue<ll> Can_remain_relaxed;
    vector<ll> visited(n + 1, false);
    dis[1] = 0;
    for(int i = 0 ; i < m ; i++) 
    {
        int a, b, w;
        cin >> a >> b >> w;
        Map[a].push_back({b,-w});
    }
    for(int i = 0 ; i < n - 1 ; i++) //Bellman 
    {
        for(int j = 1 ; j <= n ; j++)
        {
            for(auto &[v,w] : Map[j])
            {
                if(dis[j] + w < dis[v] && dis[j] != INF)
                    dis[v] = dis[j] + w;
            }
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        for(auto &[v,w] : Map[i])
        {
            if(dis[i] + w < dis[v] && dis[i] != INF)
            {
                if(!visited[v])
                {
                    Can_remain_relaxed.push(v);
                    visited[v] = true;
                }
            }
        }
    }
    while(!Can_remain_relaxed.empty()) 
    {
        int now = Can_remain_relaxed.front();
        Can_remain_relaxed.pop();
        for(auto &[v,w] : Map[now])
        {
            if(!visited[v])
            {
                visited[v] = true;
                Can_remain_relaxed.push(v);
            }
        }
    }
    if(visited[n])
        cout << -1 << "\n";
    else
        cout << -dis[n] << "\n";
    return 0;
}