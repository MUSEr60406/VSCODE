#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int r, c, x, y;
    char D;
    string command;
    while(cin >> r >> c >> x >> y >> D >> command)
    {
        bool Map[51][51] = {false}, lost = false;
        int d, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        //0 = n, 1 = e, 2 = s, 3 = w
        map<char, int> f = {{'N',0}, {'E',1}, {'S',2}, {'W',3}};
        char F[4] = {'N', 'E', 'S', 'W'};
        d = f[D];
        for(int i = 0 ; i < command.size() ; i++) //simulate
        {
            if(command[i] == 'R')
            {
                d = (d + 1) % 4;
            }
            else if(command[i] == 'L')
            {
                d--;
                if(d < 0)
                    d = 3;
            }
            else
            {
                int nx = x + dx[d], ny = y + dy[d];
                if(nx > r || nx < 0 || ny > c || ny < 0)
                {
                    if(Map[x][y])
                        continue;
                    Map[x][y] = true; //標記
                    lost = true;
                    break;
                }
                else
                {
                    x = nx;
                    y = ny;
                }
            }
        }
        if(!lost)
            cout << x << " " << y << " " << F[d] << "\n";
        else
            cout << x << " " << y << " " << F[d] << " LOST\n";
    }   

    return 0;
}