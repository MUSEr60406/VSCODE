#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define INF 1e9
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> MAP(n + 1);
    vector<int> dis(n + 1, INF);
    vector<int> cycle;
    vector<bool> visited(n + 1, false);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        MAP[a].push_back({b, w});
    }
    dis[1] = 0;
    for(int k = 0 ; k < n - 1 ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(auto &[v, w] : MAP[i])
            {
                if(dis[i] + w < dis[v] && dis[i] != INF)
                    dis[v] = dis[i] + w;        
            }
        }
    }
    for(int k = 0 ; k < n - 1 ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(auto &[v, w] : MAP[i])
            {
                if(dis[i] + w < dis[v] && dis[i] != INF)
                {
                    dis[v] = dis[i] + w;  
                    if(!visited[i])
                    {
                        cycle.push_back(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    if(cycle.empty())
        cout << "NO\n";
    else
    {
        cout << cycle.size() << "\n";
        int end = cycle[0];
        cout << "YES\n";
        for(int i = 0 ; i < cycle.size(); i++)
        {
            cout << cycle[i] << " ";
            if(i > 0 && cycle[i] == end)
                break;
        }
        cout << end;
    }
    return 0;
}