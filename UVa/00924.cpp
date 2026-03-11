#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

vector<vector<int>> fri;
int E, T;
void bfs(int start)
{
    int day = 0;
    vector<pii> day_person;
    day_person.push_back({day, start});
    vector<bool> visited(E, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(int &v : fri[now])
        {
            if(visited[v])
                continue;
            day_person.push_back({day, v});
            visited[v] = true;
        }
        day++;
    }
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> E;
    fri.assign(E, {});
    for(int i = 0 ; i < E ; i++)
    {
        int temp;
        cin >> temp;
        fri[i].push_back(temp);
    }
    cin >> T;
    for(int i = 0 ; i < T ; i++)
    {
        int source;
        cin >> source;
        bfs(source);
    }


    return 0;
}