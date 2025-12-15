#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
void bfs(int i, vector<vector<int>> &Map, vector<int> &path)
{
    queue<int> q;
    q.push(i);
    path[i] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int i : Map[now])
        {
            if(path[i] == -1)
            {
                path[i] = path[now] + 1;
                q.push(i);
            }
        }
    }
}
int main()
{
    int Case = 1;
    while(true)
    {
        vector<vector<int>> Map(101, vector<int>{});
        vector<int> node;
        vector<bool> exit(101, false);
        int a, b;
        double sum = 0;
        while(cin >> a >> b && a != 0 && b != 0)
        {
            if(!exit[a])
                node.push_back(a);
            if(!exit[b])
                node.push_back(b);
            exit[a] = exit[b] = true;
            Map[a].push_back(b);
        }
        if(node.empty())
            break;
        sort(node.begin(), node.end());
        for(int i : node)
        {
            vector<int> path(node.back() + 1, -1);
            bfs(i, Map, path);
            for(int i = 1 ; i <= path.size() ; i++)
                if(exit[i]) sum += path[i];
        }
        cout << "Case " << Case++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << sum / (node.size() * ( node.size() - 1 )) << " clicks\n";
    }
}