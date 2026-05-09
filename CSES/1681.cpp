#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m; 
    cin >> n >> m;
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false));
    vector<ll> dis(n + 1, 0);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = 0;
    }

    return 0;
}