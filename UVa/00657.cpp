#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<string> M;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, w, h, X;
void bfsX(int startx, int starty)
{
    queue<pii> q;
    q.push({startx, starty});
    M[startx][starty] = '*';
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if(newx < 0 || newx >= h || newy < 0 || newy >= w || M[newx][newy] != 'X')
                continue;
            //
            M[newx][newy] = '*';
            q.push({newx, newy});
        }
    }
    X++;
    
}
int bfs(int startx, int starty)
{
    int dice = 0;
    if(M[startx][starty] == 'X')
        bfs(startx, starty);
    queue<pii> q;
    q.push({startx, starty});
    M[startx][starty] = '.';
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i++)
        {
            int newx = x + dx[i], newy = y + dy[i];
            if(newx < 0 || newx >= h || newy < 0 || newy >= w || M[newx][newy] == '.')
                continue;
            //
            if(M[newx][newy] == 'X')
                bfsX(newx, newy);
            M[newx][newy] = '.';
            q.push({newx, newy});
        }
    }
    return dice;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int cnt = 0;
    vector<int> dice;
    while(cin >> w >> h && w != 0 && h != 0)
    {
        X = 0;
        M.clear();
        dice.clear();
        for(int i = 0 ; i < h ; i++)
        {
            string s;
            cin >> s;
            M.push_back(s);
        }
        for(int i = 0 ; i < h ; i++)
        {
            for(int j = 0 ; j < w ; j++)
            {
                if(M[i][j] != '.')
                {
                    X = bfs(i, j);
                    dice.push_back(X);
                }
            }
        }
        sort(dice.begin(), dice.end());
        cout << "Throw " << ++cnt << "\n";
        for(int &i : dice)
            cout << i << " ";
        cout << "\n";
    }

    return 0;
}