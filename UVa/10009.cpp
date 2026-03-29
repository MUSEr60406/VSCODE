#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<int> path;
vector<int> parent;
void bfs(int st, int en)
{
    queue<int> q;
    q.push(st);
    path[st] = 0;

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin.ignore();
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        tree.clear();
        tree.resize(m);
        for(int i = 0 ; i < m ; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            tree[c1[0] - 'A'].push_back(c2[0] - 'A');
            tree[c2[0] - 'A'].push_back(c1[0] - 'A');
        }
        for(int i = 0 ; i < n ; i++)
        {
            path.assign(26, -1);
            parent.assign(26, -1);
            string st, en;
            cin >> st >> en;
            bfs(st[0] - 'A', en[0] - 'A');
        }
    }

    return 0;
}