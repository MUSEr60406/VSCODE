#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
map<int ,pii> g;
vector<int> cake;
void dfs(int now, int c)
{
    int people = 1;
    if(g[now].first != -1) people++;
    if(g[now].second != -1) people++;
    if(people == 1) //無子節點
    {
        cake[now] = c;
        return;
    }
    int d = c / people;
    cake[now] = d;
    if(c % people != 0) cake[now] += c % people;
    if(g[now].first != -1)
        dfs(g[now].first, d);
    if(g[now].second != -1)
        dfs(g[now].second, d);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    cake.assign(n, 0);
    for(int i = 0 ; i < n ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g.insert({a, {b,c}});
    }
    dfs(0, k);
    for(int i : cake)
        cout << i << " ";
    return 0;
}