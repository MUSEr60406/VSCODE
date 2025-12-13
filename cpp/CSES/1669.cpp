//Round Trip 
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> city;
vector<bool> visited;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;
bool dfs(int start, int end)
{
    visited[start] = true;
    for(int i : city[start])
    {
        if(i == end) continue;
        if(visited[i])
        {
            cycle_start = i;
            cycle_end = start;
            return true;
        }
        parent[i] = start;
        if(dfs(i, start)) return true;
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    city.assign(n + 1, {});
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i] && dfs(i, -1))
            break; // 找到環就停止
    }
    if(cycle_start == -1)
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    path.push_back(cycle_start);
    for(int i = cycle_end; i != cycle_start; i = parent[i])
        path.push_back(i);
    path.push_back(cycle_start);
    cout << path.size() << "\n";
    for(int i : path)
        cout << i << " ";
    cout << "\n";
    return 0;
}
