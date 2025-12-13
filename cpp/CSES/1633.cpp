//Dice Combinations
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, mod = 1e9 + 7;
    cin >> n;
    vector<int> dp(n + 1, 0);
    dp[0] = 1; //0
    for(int i = 1 ; i <= n ; i++)
    {
        for(int x = 1 ; x <= 6 ; x++)
        {
            if(i - x >= 0)
                dp[i] += dp[i - x];
                dp[i] %= mod;
        }
    }
    cout << dp[n];
    return 0;
}