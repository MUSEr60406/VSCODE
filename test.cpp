#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, m;
    bool pos = true;
    cin >> n >> m;
    vector<vector<ll>> fri(n + 1);
    vector<int> team(n + 1, 0);
    for(int i = 0 ; i < m ; i++)
    {
        ll a, b;
        cin >> a >> b;
        fri[a].push_back(b);
        fri[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(team[i] == 0)
        {
            queue<ll> q;
            q.push(i);
            team[i] = 1;
            while(!q.empty())
            {
                ll now = q.front();
                q.pop();
                for(ll &v : fri[now])
                {
                    if(team[v] == 0)
                    {
                        team[v] = (team[now] == 1 ? 2 : 1);
                        q.push(v);
                    }
                    else if(team[now] == team[v])
                        pos = false;
                }
            }
        }
    }
    if(pos)
        for(int i = 1 ; i <= n ; i++)
            cout << team[i] << " ";
    else
        cout << "IMPOSSIBLE";
    cout << "\n";
    return 0;
}