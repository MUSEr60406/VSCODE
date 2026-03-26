#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<string> g;
void bfs()
{
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    queue<pii> q;
    q.push({0, 0});
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    while(cin >> N)
    {
        g.clear();
        g.resize(N);
        for(auto &s : g)
            cin >> s;
        bfs();
    }

    return 0;
}