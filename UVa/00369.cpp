#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;
unsigned ll c[101][101];
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
                c[i][j]  =c[i - 1][j - 1] + c[i - 1][j - 1];
        }
    }
    int m, n;

    return 0;
}