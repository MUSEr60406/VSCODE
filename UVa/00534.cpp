#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n ,count = 0;
    int M[201][201];
    while(cin >> n && n != 0)
    {
        vector<pii> stone;
        for(int i = 0 ; i < n ; i++)
        {
            int x, y;
            cin >> x >> y;
            stone.push_back({x, y});
        }
    }

    return 0;
}