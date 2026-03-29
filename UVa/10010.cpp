#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int m, n;
vector<string> g;
set<pii> Find;
set<pii> notFind;
pii f(string s)
{
    Find.clear();
    notFind.clear();
    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(g[i][j] == s[0])
            {
                for(int k = 0 ; k < 8 ; k++)
                {
                    bool match = true;
                    int x = i, y = j;
                    for(int l = 1 ; l < s.size() ; l++)
                    {
                        x += dx[k], y += dy[k];
                        if(x < 0 || x >= m || y < 0 || y >= n || g[x][y] != s[l])
                        {
                           match = false;
                           break;
                        }
                    }
                    if(match)
                        notFind.insert({i, j});
                    else
                        Find.insert({i, j});
                }
            }
        }
    }
    if(!Find.empty())
        return *Find.begin();
    else
        return *notFind.begin();
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        g.clear();
        g.resize(m);  
        for(string &s : g)
        {
            cin >> s;
            for(char &c : s)
                c = tolower(c);
        }
        int k;
        vector<pii> ans;
        cin >> k;
        for(int i = 0 ; i < k ; i++)
        {
            string s;
            cin >> s;
            for(char &c : s)
                c = tolower(c);
            ans.push_back(f(s));
        }
        for(auto &[x, y] : ans)
            cout << x + 1 << " " << y + 1 << "\n";
        if(t)
            cout << "\n";
    }

    return 0;
}