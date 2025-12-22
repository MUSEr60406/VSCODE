//Shortest Route II
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{    
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<ll>> cost(n + 1, vector<ll> (n + 1, LLONG_MAX / 2));
    for(int i = 1 ; i < n + 1 ; i++)
        cost[i][i] = 0;
    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cost[a][b] = cost[b][a] = min(cost[a][b], (ll)c);
    }
    for(int k = 1 ; k < n + 1 ; k++)
        for(int i = 1 ; i < n + 1 ; i++)
            for(int j = 1 ; j < n + 1 ; j++)
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(cost[a][b] > 1e13)
            cout << -1;
        else
            cout << cost[a][b];
        cout << "\n";
    }
    return 0;
}