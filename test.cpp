#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
void bfs(int start, vector<vector<int>> &Map, vector<int> &path)
{
    queue<int> q;
    q.push(start);
    path[start] = 0;
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int Case = 1;
    while(true)
    {
        double sum = 0;
        vector<vector<int>> Map(101, vector<int>());
        vector<int> node;
        vector<bool> exit(101, false);
        int a, b;
        while(cin >> a >> b && a != 0 && b != 0)
        {
            if(!exit[a])
                node.push_back(a);
            if(!exit[b])
                node.push_back(b);
            Map[a].push_back(b);
            exit[a] = exit[b] = true;
        }
        if(node.empty())
            break;
        sort(node.begin(), node.end());
        for(int i : node)
        {
            vector<int> path(node.back() + 1, -1);
            bfs(i, Map, path);
            for(int i = 1 ; i <= path.size() ; i++)
                if(exit[i])
                    sum += path[i];
        }
        cout << "Case " << Case++ << ": average length between pages = ";
        cout << fixed << setprecision(3) << sum / (node.size() * ( node.size() - 1 )) << " clicks\n";
    }
    return 0;
}