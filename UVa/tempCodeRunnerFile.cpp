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
        vector<vector<int>> dp(w + 1, vector<int>(h + 1, 0)), wolf(w + 1, vector<int>(h + 1, 0));
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            wolf[x][y] = 1;
        }
        dp[0][0] = 1;
        for(int i = 0 ; i <= w ; i++)
        {
            for(int j = 0 ; j <= h ; j++)
            {
                if((i == 0 && j == 0) || wolf[i][j] == 1)
                    continue;
                if(i > 0) 
                    dp[i][j] = dp[i - 1][j] + 1;
                if(j > 0) 
                    dp[i][j - 1] = dp[i][j - 1];
            }
        }
        if(dp[w][h] > 2)
            cout << "There are " << dp[w][h] <<" paths from Little Red Riding Hood's house to her grandmother's house.";
        else if(dp[w][h] == 1)
            cout << "There are one paths from Little Red Riding Hood's house to her grandmother's house.";
        else
            cout << "There is no path.";
        cout << "\n";
    }

    return 0;
}