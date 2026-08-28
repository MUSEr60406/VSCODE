#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> M(n);
    for(int i = 0 ; i < n ; i++)
        cin >> M[i];
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(M[i][j] == '#')
                continue;
        }
    }

    return 0;
}