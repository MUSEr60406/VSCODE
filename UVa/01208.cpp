#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
struct edge
{
    int u, v, w;
};
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
bool ANS(edge a, edge b)
{
    if(a.w == b.w)
    {
        if(a.u == b.u)
            return a.v < b.v;
        else
            return a.u < b.u;
    }
    else
        return a.w < b.w;
        
}
int t, n, par[26];
vector<edge> g;
vector<edge> ans;
int read()
{
    int num = 0;
    char c  = getchar();
    while(c != EOF && (c < '0' || c > '9'))
        c = getchar();
    while(c == EOF)
        return -1;
    while(c >= '0' && c <= '9')
    {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return num;
}
int find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = find(par[x]); //路徑壓縮
}
void kruskal()
{
    sort(g.begin(), g.end(), cmp);
    for(int i = 0 ; i < n ; i++)
        par[i] = i;
    for(int i = 0 ; i < g.size() ; i++)
    {
        int x = find(g[i].u), y = find(g[i].v);
        if(x != y)
        {
            par[x] = y;
            ans.push_back({g[i].u, g[i].v, g[i].w});
        }
    }
    sort(ans.begin(), ans.end(), ANS);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Case = 1;
    t = read();
    while(t--)
    {
        g.clear();
        ans.clear();
        memset(par,0,sizeof(par));
        n = read();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int w = read();
                if(w > 0)
                    g.push_back({i, j, w});
            }
        }
        kruskal();
        cout << "Case " << Case++ << ":\n";
        for(edge &i : ans)
            cout << (char)(i.u + 'A') << "-" << (char)(i.v + 'A') << " " << i.w << "\n";
    }

    return 0;
}