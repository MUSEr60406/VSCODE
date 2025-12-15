#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ppv pair<int,vector<int>>
using namespace std;
int n;
ppv bfs(int start, vector<vector<int>> &fam)
{
    queue<int> q;
    q.push(start);
    int farthest_node = start;
    vector<int> distance(n,-1);
    distance[start] = 0;
    while(q.size())
    {
        int now = q.front();
        q.pop();
        for(int i : fam[now]) 
        {
            if(distance[i] == -1)
            {
                distance[i] = distance[now] + 1;
                q.push(i);
                if(distance[i] > distance[farthest_node]) farthest_node = i;
            }
        }
    }
    return  make_pair(farthest_node,distance);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<vector<int>> fam(n);
    for(int i = 0 ; i < n ; i++)
    {
        int parent, child;
        cin >> parent >> child;
        fam[parent].push_back(child);
        fam[child].push_back(parent);
    }
    auto first = bfs(0,fam);
    int farthest_node = first.first;
    auto second = bfs(farthest_node,fam);
    int longest = 0;
    for(int i : second.second)
    {
        if(i > longest)
        longest = i;
    }
    cout << longest << "\n";
    return 0;
    
}