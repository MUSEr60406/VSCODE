#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int g, n, p[1005] = {0}, w[1005] = {0}, dp[35] = {0};
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> p[i] >> w[i];
        cin >> g;
        while(g--)
        {
            int max_w;
            cin >> max_w;
            memset(dp, 0, sizeof(dp));
        }
    }
    

    return 0;
}