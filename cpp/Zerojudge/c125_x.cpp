#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<cmath>
#define pii pair<int,int>
using namespace std;
double d(int x, int y, int x1, int y1)
{
    return sqrt(abs(pow(x-x1,2)) + abs(pow(y-y1,2)));
}
int main()
{
    int t, count = 1;
    while(t != 0)
    {
        double ans = INT_MAX, max_dis = 0;
        bool visited[200] = {0};
        cin >> t;
        vector<pii> stone(t);
        pii ii;
        for(int i = 0 ; i < t ; i++)
        {
            int x, y;
            cin >> x >> y;
            if(i == 1)
                ii = {x,y};
            else
                stone.push_back({x,y});
        }
        stone.push_back(ii);
        for(int i = 0 ; i < t ; i++)
        {
            for(int j = 0 ; j < t ; j++)
            {
                double dis = d(stone[i].first, stone[i].second, stone[j].first, stone[j].second);
                if(dis > max_dis) max_dis = dis;
            }
        }
        while(true)
        {
            for(int i = 0 ; i < t ; i++)
            {
                for(int j = 0 ; j < t ; j++)
                {
                    double dis = d(stone[i].first, stone[i].second, stone[j].first, stone[j].second);
                    if(visited == 0 && dis <= max_dis)
                    {
                        visited[j] = dis;
                        if(visited[t-1] < ans) ans = visited[t-1];
                    }
                }
            }
        }
        cout << "Scenario #" << count << "\n" << "Frog Distance = " << ans;
        count++;
        if(t) cout << "\n";
    }
    return 0;
}