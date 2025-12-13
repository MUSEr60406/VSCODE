//Labyrinth
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int n, m;
pii position[2];
void bfs(vector<string> &MAP, vector<vector<int>> &visited, vector<vector<char>> &DIR)
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    char move[4] = {'R', 'D', 'L', 'U'};
    queue<pii> q;
    q.push(position[0]);
    visited[position[0].first][position[0].second] = 0;
    while(!q.empty())
    {
        pii p = q.front(); 
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int newx = p.first + dx[i], newy = p.second + dy[i];
            if(newx < 0 || newy < 0 || newx >= n || newy >= m || visited[newx][newy] != -1 || MAP[newx][newy] == '#') 
                continue;
            visited[newx][newy] = visited[p.first][p.second] + 1;
            DIR[newx][newy] = move[i];
            q.push({newx, newy});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    bool findA = false, findB = false;
    cin >> n >> m;
    vector<string> MAP(n);
    vector<vector<int>> visited(n, vector<int>(m, -1));
    vector<vector<char>> DIR(n, vector<char>(m));

    for(int i = 0; i < n; i++)
    {
        cin >> MAP[i];
        if(!(findA && findB))
        {
            for(int j = 0; j < m; j++)
            {
                if(MAP[i][j] == 'A') 
                {
                    position[0] = {i, j}; 
                    findA = true;
                }
                if(MAP[i][j] == 'B')
                { 
                    position[1] = {i, j};
                    findB = true;
                }
            }
        }
    }

    if(findA && findB)
    {
        bfs(MAP, visited, DIR);
        if(visited[position[1].first][position[1].second] != -1)
        {
            cout << "YES\n" << visited[position[1].first][position[1].second] << "\n";
            int nowx = position[1].first, nowy = position[1].second;
            string path{""};
            unordered_map<char,pii> rev = {{'R',{0,-1}},{'L',{0,1}},{'U',{1,0}},{'D',{-1,0}}};
            while(MAP[nowx][nowy] != 'A')
            {
                char c = DIR[nowx][nowy];
                path += c;
                nowx += rev[c].first;
                nowy += rev[c].second;
            }
            reverse(path.begin(), path.end());
            cout << path << "\n";
        }
        else cout << "NO\n"; 
    }
    else  
        cout << "NO\n";

    return 0;   
}
