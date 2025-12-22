//Building Teams
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> students;
vector<int> teams;
bool possible = true;
void bfs(int i)
{
	queue<int> q;
	q.push(i);
	teams[i] = 1;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i : students[now])
		{
			if(teams[i] == 0)
			{
				teams[i] = teams[now] == 1 ? 2 : 1;
				q.push(i);
			}
			else if(teams[now] == teams[i])
			{
				possible = false;
				return;
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	students.assign(n + 1, vector<int>());
	teams.assign(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		students[a].push_back(b);
		students[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if(teams[i] == 0)
			bfs(i);
		if(!possible)
			break;
	}
	if(possible)
	{
		teams.erase(teams.begin());
		for(int i : teams)
			cout << i << " ";
	}
	else
		cout << "IMPOSSIBLE";
	cout << "\n";
	return 0;
}
