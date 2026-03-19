#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<string> M;
int bfs(int startx, int starty)
{
    int dice = 0;
    if(M[startx][starty] == 'X')
        dice++;
    queue<pii> q;
    q.push({startx, starty});
    M[startx][starty] = '.';
    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int w, h;
    vector<int> dice;
    while(cin >> w >> h && w != 0 && h != 0)
    {
        M.clear();
        for(int i = 0 ; i < w ; i++)
        {
            string s;
            cin >> s;
            M.push_back(s);
        }
        for(int i = 0 ; i < w ; i++)
        {
            for(int j = 0 ; j < h ; j++)
            {
                if(M[i][j] != '.')
                    dice.push_back(bfs(i, j));
            }
        }
    }

    return 0;
}