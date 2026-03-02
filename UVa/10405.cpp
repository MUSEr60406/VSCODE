#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int dp[1200][1200];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        if(s1[0] == s2[0])
            dp[1][1] = 1;
    }

    return 0;
}