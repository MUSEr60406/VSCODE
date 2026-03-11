#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

vector<vector<int>> fri;
int E, T;
void bfs(int start)
{
    int last_day = -1;
    map<int,int> person_day;
    vector<bool> visited(E, false);
    queue<int> q;
    person_day.insert({start, 0});
    visited[start] = true;
    q.push(start);
    while(!q.empty())
    {
        int now = q.front();
        if(last_day < person_day[now])
            last_day = person_day[now];
        q.pop();
        for(int &v : fri[now])
        {
            if(visited[v])
                continue;
            person_day.insert({v, person_day[now] + 1});
            q.push(v);
            visited[v] = true;
        }
    }
    if(person_day.size() == 1)
    {
        cout << "0\n";
        return;
    }
    vector<int> count(last_day + 1, 0);
    int max = -1, day;
    for(auto &i : person_day)
        count[i.second]++;
    for(int i = 1 ; i <= last_day ; i++)
    {
        if(count[i] > max)
        {
            max = count[i];
            day = i;
        }
    }
    cout << max << " " << day << "\n";
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
        fri[i].resize(N);
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