#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define pii pair<int,int>
using namespace std;
bool visited[500][500] = {false};
vector<string> MAP(500);
int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1}, m, n;

int bfs(pii p)
{
    int a = 0;
    bool no_way = true;
    queue<pii> q;
    q.push({p.first, p.second});
    while(!q.empty())
    {
        pii now;
        now = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = now.first + dx[i], newy = now.second + dy[i];
            if(newx >= m || newx < 0 || newy >= n || newy < 0 || visited[newx][newy] == true || MAP[newx][newy] == 'X') 
                continue;
            else
            {
                no_way = false;
                a++;
                q.push({newx,newy});
                visited[newx][newy] = true;
            }

        }
    }
    if(no_way && a == 0) //只有一格
        return 1;
    else
        return a;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin >> m >> n)
    {
        int max = 0, A = 0, ans = 0;
        for(int i = 0 ; i < m ; i++)
            cin >> MAP[i];

        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(visited[i][j] == false && MAP[i][j] == 'J')
                {
                    A = bfs({i,j});
                    if(A > max) max = A;
                    ans++;
                }
                else
                    continue;
            }
        }
        cout << ans << " " << max << "\n";

        for(int i = 0 ; i < m ; i++) //重製拜訪陣列給後續測資用
            for(int j = 0 ; j < n ; j++)
                visited[i][j] = false;
    }
    return 0;
}