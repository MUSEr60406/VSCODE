//Monsters
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#define pii pair<int,int>
using namespace std;
int n, m;
vector<string> maze;
vector<vector<bool>> visited;
vector<vector<char>> dir;
vector<vector<int>> timeA;
vector<vector<int>> timeM;
vector<pii> Exit{};
vector<pii> Monsters{};
pii start;
void bfs(char c)
{
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    char move[4] = {'R','D','L','U'};
    visited.assign(n, vector<bool> (m, false));
    if(c == 'A')
    {
        queue<pii> qA;
        qA.push(start);
        visited[start.first][start.second] = true;
        timeA[start.first][start.second] = 0;
        while(!qA.empty())
        {
            pii now = qA.front();
            qA.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nx = now.first + dx[i], ny = now.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || 
                    visited[nx][ny] || maze[nx][ny] == '#' || timeA[now.first][now.second]+1 >= timeM[nx][ny])
                    continue;
                visited[nx][ny] = true;
                timeA[nx][ny] = timeA[now.first][now.second] + 1;
                dir[nx][ny] = move[i];
                qA.push({nx,ny});
            }
        }
    }
    else if(c == 'M')
    {
        queue<pii> qM;
        for(auto [x,y] : Monsters)
        {
            qM.push({x,y});
            visited[x][y] = true;
            timeM[x][y] = 0;
        }
        while(!qM.empty())
        {
            pii now = qM.front();
            qM.pop();
            for(int i = 0 ; i < 4 ; i++)
            {
                int nx = now.first + dx[i], ny = now.second + dy[i];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || maze[nx][ny] == '#')
                    continue;
                visited[nx][ny] = true;
                timeM[nx][ny] = timeM[now.first][now.second] + 1;
                qM.push({nx,ny});
            }
        } 
    }
}
int main()
{
    cin >> n >> m;
    maze.assign(n,{});
    visited.assign(n, vector<bool> (m, false));
    dir.assign(n, vector<char> (m, -1));
    timeA.assign(n, vector<int> (m, 1e9));
    timeM.assign(n, vector<int> (m, 1e9));
    for(int i = 0 ; i < n ; i++)
    {        
        cin >> maze[i];
        for(int j = 0 ; j < m ; j++)
        {
            if((i == 0 || j == 0 || i == n - 1 || j == m - 1) && maze[i][j] == '.')
                Exit.push_back({i,j});
            if(maze[i][j] == 'A')
                start = {i,j};
            if(maze[i][j] == 'M')
                Monsters.push_back({i,j});
        }
    }
    if(start.first == 0 || start.second == 0 || start.first == n - 1 || start.second == m - 1)
    {
        cout << "YES\n";
        return 0;
    }
    if(Exit.empty())
    {
        cout << "NO\n";
        return 0;
    }
    if(!Monsters.empty())
        bfs('M');
    bfs('A');
    bool escape = false;
    unordered_map<char,pii> rev = {{'R',{0,-1}},{'L',{0,1}},{'U',{1,0}},{'D',{-1,0}}};
    for(auto [endx,endy] : Exit)
    {
        int nowx = endx, nowy = endy;
        if(timeA[nowx][nowy] < timeM[nowx][nowy])
        {
            string path{""};
            while(maze[nowx][nowy] != 'A')
            {
                char c = dir[nowx][nowy];
                path += c;
                nowx += rev[c].first;
                nowy += rev[c].second;
            }
            reverse(path.begin(), path.end());
            cout << "YES\n" << path.size() << "\n" << path;
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}