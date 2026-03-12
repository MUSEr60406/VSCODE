#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> edge(200001, vector<int>());
vector<bool> dis(2000001, -1);
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int parent, child;
        cin >> parent >> child;
        edge[parent].push_back(child);
        edge[child].push_back(parent);
    }
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
    }

    return 0;
}