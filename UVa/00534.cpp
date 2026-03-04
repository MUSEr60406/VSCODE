#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll M[201][201];
ll pow(int n, int p)
{
    int temp = 1;
    for(int i = 0 ; i < p ; i++)
        temp *= n;
    return temp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n ,count = 0;
    while(cin >> n && n != 0)
    {
        vector<pii> stone(n);
        for(auto &i : stone)
            cin >> i.first >> i.second;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                ll temp = pow(stone[i].first - stone[j].first, 2) + pow(stone[i].second - stone[j].second, 2);
                M[i][j] = temp;
            }
        }

        for(int k = 0 ; k < n ; k++)
            for(int i = 0 ; i < n ; i++)
                for(int j = 0 ; j < n ; j++)
                    M[i][j] = min(M[i][j], max(M[i][k], M[k][j]));

        double ans = sqrt(M[0][1]);
        cout << "Scenario #" << ++count <<"\nFrog Distance = " << fixed << setprecision(3) << ans << "\n\n";
    }
    return 0;
}