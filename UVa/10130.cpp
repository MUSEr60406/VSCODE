#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() 
{
    int N;
    cin >> N;
    vector<pair<int, int>> items(N);
    for (int i = 0; i < N; ++i)
        cin >> items[i].first >> items[i].second;

    vector<int> dp(31, 0);
    for (int i = 0; i < N; ++i) 
    {
        int p = items[i].first;  
        int w = items[i].second; 
        for (int j = 30; j >= w; --j)
            dp[j] = max(dp[j], dp[j - w] + p);
    }
    
    int G;
    cin >> G;
    long long total_value = 0;
    for (int i = 0; i < G; ++i) 
    {
        int mw;
        cin >> mw;
        total_value += dp[mw];
    }

    cout << total_value << "\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}