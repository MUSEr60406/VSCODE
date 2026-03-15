#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;
ll c[101][101];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for(int i = 0 ; i <= 100 ; i++)
    {
        for(int j = 0 ; j <= 100 ; j++)
        {
            if(j == 1)
                c[i][j] = i;
            else if(i == j)
                c[i][j] = 1;
            else if(i < j)
                c[i][j] = 0;
            else
                c[i][j]  =c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    int n, m;
    while(cin >> n >> m && n != 0 && m != 0)
        cout << n << " things taken " << m << " at a time is " << c[n][m] << " exactly.\n";

    return 0;
}