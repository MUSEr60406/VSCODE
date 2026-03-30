#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int read()
{
    int num = 0;
    char c  = getchar();
    while(c != EOF && (c < '0' || c > '9'))
        c = getchar();
    while(c == EOF)
        return -1;
    while(c >= '0' && c <= '9')
    {
        num = num * 10 + (c - '0');
        c = getchar();
    }
    return num;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<tuple<int, int, int>> e;
    int t, n, g[26][26];
    cin >> t;
    while(t--)
    {
        memset(g, 0, sizeof(g));
        cin >> n;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                g[i][j] = read();
                if(g[i][j] > 0)
                    e.push_back(g[i][j], i, j);
            }
        }
    }

    return 0;
}