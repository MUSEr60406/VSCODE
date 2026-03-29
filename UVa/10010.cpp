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
    int len = s.size();
    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1}, dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(g[i][j] == s[0])
            {
                bool fail = false;
                int x = i, y = j;
                for(int k = 0 ; k < 8 ; k++)
                {
                    for(int l = 0 ; l < len ; l++)
                    {
                        int newx = x + dx[k], newy = y + dy[k];
                        if(newx < 0 || newx >= m || newy > 0 || newy >= n || g[newx][newy] != s[l])
                        {
                            fail = true;
                            break;
                        }
                        x = newx, y = newy;
                    }
                    if(fail)
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
            cout << x << " " << y << "\n";
        if(t)
            cout << "\n";
    }

    return 0;
}