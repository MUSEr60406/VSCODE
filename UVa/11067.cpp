#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, h;
    while(cin >> w >> h && w != 0 && h != 0)
    {
        vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0));
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            dp[x][y] = INT_MAX / 2;
        }
        for(int i = 0 ; i <= w ; i++)
        {
            for(int j = 0 ; j <= h ; j++)
            {

            }
        }
        
    }

    return 0;
}