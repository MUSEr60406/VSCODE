#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<int> path;
vector<int> parent;
vector<pii> test_case;
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
        path.assign(26, -1);
        parent.assign(26, -1);
        test_case.clear();
        for(int i = 0 ; i < m ; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            
        }
    }

    return 0;
}