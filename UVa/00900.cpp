#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    long long int dp[51];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= 50 ; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    while(cin >> n && n != 0)
        cout << dp[n] << "\n";
    system("pause");
    return 0;
}