#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int bfs(pii p, vector<string> &Map)
{
    int ans = 1, dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
    queue<pii> q;
    q.push(p);
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = p.first + dx[i], newy = p.second + dy[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        cin.ignore();
        pii p;
        vector<string> Map;
        string s;
        cin >> p.first >> p.second;
        while(getline(cin, s))
            Map.push_back(s);
        cout << bfs(p, Map);
    }
    return 0;
}