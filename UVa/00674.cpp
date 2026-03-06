#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int dp[7489], coin[] = {1, 5, 10, 25, 50};
    dp[0] = 0;
    dp[1] = 1;
    for(int &c : coin)
    {
        for(int i = c ; i <= 7489 ; i++)
            dp[i] += dp[i - c];
    }

    return 0;
}