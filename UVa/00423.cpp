#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, INF = INT_MAX / 2;
    while(cin >> n)
    {
        int adj[105][105];
        memset(adj, INF, sizeof(adj));
        for(int i = 2 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= i - 1 ; j++)
            {
                string s;
                cin >> s;
                if(s == "x") 
                    continue;
                adj[i][j] = adj[j][i] = stoi(s);
            }
        }
        //
        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
        //
        int max = -1;
        for(int i = 2 ; i <= n ; i++)
            if(adj[1][i] > max) 
                max = adj[1][i];
        cout << max << "\n";
    }

    return 0;
}