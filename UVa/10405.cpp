#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    while(getline(cin, s1) && getline(cin, s2))
    {
        int dp[1200][1200];
        memset(dp, 0, sizeof(dp));
        for(int i = 1 ; i <= s1.length() ; i++)
        {
            for(int j = 1 ; j <= s2.length() ; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        cout << dp[s1.length()][s2.length()] << "\n";
    }
    return 0;
}