//Shortest Route I
#include<iostream>
#include<queue>
#include<vector>
#define pll pair<long,long>
#define pii pair<int,int>
using namespace std;
int main()
{   
    int n, m;
    cin >> n >> m;
    vector<vector<pll>> airline(n + 1);
    vector<long long> dis(n + 1, -1);
    dis[1] = 0;
    while(m--)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        airline[a].push_back({b, weight});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0,1}); //{dis, node}
    while(!pq.empty())
    {
        auto [d, node] = pq.top();
        pq.pop();
        if(d != dis[node])
            continue;
        for(auto &[visit, weight] : airline[node])
        {
            if(dis[visit] == -1 || dis[visit] > d + weight)
            {
                dis[visit] = d + weight;
                pq.push({dis[visit], visit});
            }
        }
    }
    dis.erase(dis.begin());
    for(auto i : dis)
        cout << i << " ";
    return 0;
}