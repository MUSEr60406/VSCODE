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
    vector<int> dis(n + 1, 0);
    vector<int> parent(n + 1, -1);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        MAP[a].push_back({b, w});
    }
    dis[1] = 0;
    for(int k = 0 ; k < n  ; k++)
    {
        for(int i = 1 ; i <= n ; i++)
        {
            for(auto &[v, w] : MAP[i])
            {
                if(dis[i] + w < dis[v])
                    dis[v] = dis[i] + w;        
            }
        }
    }
    return 0;
}