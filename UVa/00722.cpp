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
    Map[p.first][p.second] = '1';
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = p.first + dx[i], newy = p.second + dy[i];
            if(newx < 0 || newx >= Map.size() || newy < 0 || newy >= Map[0].length() || Map[newx][newy] == '1')
                continue;
            Map[newx][newy] = '1';
            q.push({newx, newy});
            ans++;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int x, y;
        vector<string> Map;
        string s;
        cin >> x >> y;
        cin.ignore();
        while(getline(cin, s) && !s.empty()) 
            Map.push_back(s);
        cout << bfs({x - 1, y -1}, Map);
        if(n)
            cout << "\n";
    }
    return 0;
}