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
        bool Map[51][51] = {false};
        int d, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
        //0 = n, 1 = e, 2 = s, 3 = w
        map<char, int> f = {{'N',0}, {'E',1}, {'S',2}, {'W',3}};
        d = f[D];
        for(int i = 0 ; i < command.size() ; i++) //simulate
        {
            if(command[i] == 'R')
                d = (d + 1) % 4;
            else if(command[i] == 'L')
            {
                d--;
                if(d < 0)
                    d = 3;
            else
                x += dx[d], y += dy[d];
        }
    }   

    return 0;
}