#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<int>> g(5);
    g[0].push_back(1);
    g[0].push_back(2);
    g[1].push_back(0);
    g[1].push_back(2);
    g[1].push_back(4);      
    g[2].push_back(3);
    g[3].push_back(1);
    g[2].push_back(4);
    g[4].push_back(1);
    queue<int> q;
    vector<int> path(5, -1);
    q.push(0);
    path[0] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int v : g[now])
        {
            if(path[v] == -1)
            {
                path[v] = path[now] + 1;
                q.push(v);
            }
        }
    }
    for(int i = 0 ; i < path.size() ; i++)
        cout << i << ": " << path[i] << "\n";

    return 0;
}