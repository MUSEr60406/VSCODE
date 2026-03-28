#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> g;
vector<int> color;
bool bfs()
{
    queue<int> q;
    q.push(0);
    bool c = 1;
    color[0] = c;
    while(!q.empty())
    {
        int now = q.front();
        c = color[now];
        q.pop();
        for(int &v : g[now])
        {
            if(color[v] == -1)
            {
                color[v] = !c;
                q.push(v); 
            }
            else if(color[v] == c)
                return false;
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        g.clear();
        g.resize(n);
        color.assign(n, -1);
        int m;
        cin >> m;
        for(int i = 0 ; i < m ; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        cout << (bfs() ? "BICOLORABLE." : "NOT BICOLORABLE.") << "\n";
    }
    

    return 0;
}