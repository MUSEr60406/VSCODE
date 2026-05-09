#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<int> dis;
int bfs(int s)
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    tree.resize(n + 1);
    for(int i = 0 ; i < n ; i++)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; i++)
        cout << bfs(i) << "\n";
    return 0;
}