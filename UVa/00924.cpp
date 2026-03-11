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
    vector<bool> visited(E, false);
    queue<int> q;
    day_person.push_back({day, start});
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        day++;
        for(int &v : fri[now])
        {
            if(visited[v])
                continue;
            day_person.push_back({day, v});
            visited[v] = true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> E;
    fri.assign(E, {});
    for(int i = 0 ; i < E ; i++)
    {
        int N;
        cin >> N;
        fri[i].assign(N, {});
        for(int &j : fri[i])
            cin >> j;
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