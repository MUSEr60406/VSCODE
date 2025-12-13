#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, p, l ,r;
    cin >> n >> p >> l >> r;
    vector<vector<int>> S(n,vector<int>(1));
    vector<int> visited(n,-1);
    for(int i = 0 ; i < n ; i++)
        cin >> S[i][0];
    int move[2] = {-l,r};
    int path[2] = {l,r};

    queue<int> q;
    q.push(0);
    visited[0] = 0;
    while(!q.empty())
    {
        if(p == 0)
        {
            cout << 0 << "\n";
            return 0;
        }
        int now = q.front();
        q.pop();
        if(S[now][0] >= n || S[now][0] < 0)
    }
    visited[p] != -1 ? cout << visited[p] : cout << -1;
    cout << "\n";
    return 0;
}