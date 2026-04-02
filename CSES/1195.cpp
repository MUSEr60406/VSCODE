#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<pii>> flight;
vector<int> cost;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    flight.resize(n + 1);
    cost.assign(n + 1, -1);
    for(int i = 0 ; i < m ; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        flight[a].push_back({b, c});
    }

    return 0;
}