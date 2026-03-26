#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<pii>> MAP(m);
    for(int i = 0 ; i < n ; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        MAP[a].push_back({b, w});
    }
    return 0;
}