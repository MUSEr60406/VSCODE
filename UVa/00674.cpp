#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll int dp[8000] = {0}, coin[] = {1, 5, 10, 25, 50};
    dp[0] = 1;
    for(ll &c : coin)
    {
        for(int i = c ; i <= 7489 ; i++)
            dp[i] += dp[i - c];
    }
    int n;
    while(cin >> n)
        cout << dp[n] << "\n";
    return 0;
}