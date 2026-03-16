#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int t, scc = 0;
vector<vector<int>> g;
vector<int> ids;
vector<int> low;
vector<bool> cut;
void tarjan(int start)
{
    ids[start] = low[start] = t++;
    
    for(int &v : g[start])
    {
        if(ids[v] == 0)
            tarjan(v);
        else if(instack[v])
            low[start] = min(low[start], low[v]);
    }
    if(ids[start] == low[start])
    {
        scc++;
        while(true)
        {
            int node = st.top();
            st.pop();
            instack[node] = false;
            if(start == node)
                break;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        string s;
        g.assign(n + 1, vector<int>());
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
        cut.assign(n + 1, false);
        for(int i = 1 ; i <= n ; i++)
        {
            if(ids[i] == 0)
                tarjan(i);
        }
    }

    return 0;
}