#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
void bfs(int start_x, int start_y, vector<vector<int>> &Map, vector<vector<bool>> &visited)
{
    int dx[8] = {-1, 0, 1, 0, -1, 1, -1, 1}, dy[8] = {0, 1, 0, -1, 1, 1, -1, -1}; 
    queue<pii> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = true;

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n)
    {
        vector<vector<int>> Map(25, vector<int>(25));
        vector<vector<bool>> visited(25, vector<bool>(25, false));
        int ans = 0;
        for(int i = 0 ; i < 25 ; i++)
        {
            for(int j = 0 ; j < 25 ; j++)
            {
                if(visited[i][j] == false && Map[i][j] == 0)
                {
                    bfs(i, j, Map, visited);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}