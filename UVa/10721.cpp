#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, k;
    while(cin >> n >> m >> k)
    {
        vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
        dp[0][0] = 1;
        for (int i = 1 ; i <= k ; i++)
        {
            for (int j = 1 ; j <= n ; j++) 
            { 
                for (int w = 1 ; w <= m && w <= j ; w++) 
                    dp[i][j] += dp[i - 1][j - w];
            }
        }
        cout << dp[k][n] << "\n";
    }
    return 0;
}