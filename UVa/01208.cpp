#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int t, n, par[26];
struct edge
{
    int u, v, w;
    bool operator<(const edge &t) const
    {
        return w < t.w;
    }
};
vector<edge> g;
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
void kruskal()
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memest(par, 0, sizeof(par));
    cin >> t;
    while(t--)
    {
        g.clear();
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int w = read();
                g.push_back({i, j, w});
            }
        }
    }

    return 0;
}