#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int lenA, lenB;
    string sA, sB;
    while(cin >> lenA >> sA >> lenB >> sB)
    {
        vector<vector<int>> dp(lenA + 1,vector<int>(lenB + 1,0));
        for(int i = 0 ; i <= lenA ; i++)
            dp[i][0] = i;
        for(int i = 0 ; i <= lenB ; i++)
            dp[0][i] = i;
        for(int i = 1 ; i <= lenA ; i++)
        {
            for(int j = 1 ; j <= lenB ; j++)
            {
                if(sA[i - 1] == sB[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j - 1] + 1, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
            }
        }
        cout << dp[lenA][lenB] << "\n";
    }
    return 0;
}