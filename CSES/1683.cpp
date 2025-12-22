//Planets and Kingdoms
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> g, gr;
vector<int> visited;
vector<int> Time;
void dfsI(int start)
{
    visited[start] = 1;
    for(int v : g[start])
    {
        if(!visited[v])
            dfsI(v);
    }
    Time.push_back(start);
}
void dfsII(int start, int kingdom)
{
    visited[start] = kingdom;
    for(int v : gr[start])
    {
        if(!visited[v])
            dfsII(v, kingdom);
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, kingdom = 0;
    cin >> n >> m;
    g.assign(n + 1, vector<int>());
    gr.assign(n + 1, vector<int>());
    visited.assign(n + 1, 0);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(!visited[i])
            dfsI(i);
    }
    fill(visited.begin(), visited.end(), 0);
    reverse(Time.begin(), Time.end());
    for(int i : Time)
    {
        if(!visited[i])
            dfsII(i, kingdom++);
    }
    cout << kingdom << "\n";
    visited.erase(visited.begin());
    for(int i : visited)
        cout << i << " ";
    return 0;
}