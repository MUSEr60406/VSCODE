#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int l = -1, r = -1, c = -1;
int visited[30][30][30], dx[6] = {0,0,1,0,-1,0}, dy[6] = {0,1,0,-1,0,0}, dz[6] = {1,0,0,0,0,-1};
struct Struct
{
    int x, y, z;
};
Struct point[2];
void bfs(vector<vector<string>> &MAP)
{       
        for(int i = 0 ; i < 30 ; i++)
            for(int j = 0 ; j < 30 ; j++)
                for(int k = 0 ; k < 30 ; k++)
                    visited[i][j][k] = -1;

        queue<pair<int,pair<int,int>>> q;
        q.push({point[0].z,{point[0].x,point[0].y}});
        visited[point[0].z][point[0].x][point[0].y] = 0;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            for(int i = 0 ; i < 6 ; i++)
            {
                int newx = p.second.first + dx[i], newy = p.second.second + dy[i], newz = p.first + dz[i];
                if(newx < 0 || newy < 0 || newz < 0 || newx >= r || newy >= c || newz >= l 
                    || MAP[newz][newx][newy] == '#' || visited[newz][newx][newy] != -1) continue;
                else
                {
                    q.push({newz,{newx,newy}});
                    visited[newz][newx][newy] = visited[p.first][p.second.first][p.second.second] + 1;
                }
            }
        }
}
int main()
{
    ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin >> l >> r >> c)
    {
        if(l == 0 && r == 0 && c == 0) return 0;
        vector<vector<string>> MAP(l, vector<string> (r));
        bool find_s = false, find_e = false;
        for(int i = 0 ; i < l ; i++)
        {
            for(int j = 0 ; j < r ; j++)
            {
                string s;
                cin >> s;
                MAP[i][j] = s;
                if(!(find_s && find_e))
                {
                    for(int k = 0 ; k < s.size() ; k++)
                    {
                        if(s[k] == 'S')
                        {
                            find_s = true;
                            point[0].x = j;
                            point[0].y = k;
                            point[0].z = i;
                        }
                        else if(s[k] == 'E')
                        {
                            find_e = true;
                            point[1].x = j;
                            point[1].y = k;
                            point[1].z = i;
                        }
                    }
                }
            }
            cin.ignore();
        }
        bfs(MAP);
        if(visited[point[1].z][point[1].x][point[1].y] == -1) 
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << visited[point[1].z][point[1].x][point[1].y] << " minute(s).\n";
    }
    return 0;
}