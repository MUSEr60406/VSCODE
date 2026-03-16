#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int t;
vector<vector<int>> g;
vector<int> ids;
vector<int> low;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        string s;
        g.resize(n + 1);
        cin.ignore();
        while(getline(cin, s) && s != "0") 
        {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while(ss >> v)
            {
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        t = 0; //遍歷先後順序
        ids.assign(n + 1, 0); //0 = unvisited
        low.assign(n + 1, 0); //low-link
        for(int i = 1 ; i <= n ; i++)
        {
            if(ids[i] == 0)
                tarjan(i);
        }
    }

    return 0;
}