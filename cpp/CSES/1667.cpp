//Message Route
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> computers(n + 1);
	vector<int> visited(n + 1, -1);
	vector<int> parent(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		computers[a].push_back(b);
		computers[b].push_back(a);
	}
	//bfs
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	parent[1] = 0;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i : computers[now])
		{
			if(visited[i] == -1)
			{
				visited[i] = visited[now] + 1;
				parent[i] = now;
				q.push(i);
			}
		}
	}
	if(visited[n] != -1)
	{
		cout << visited[n] << "\n";
		vector<int> path = {n};
		int cur = parent[n];
		while(cur != 0)
		{
			path.push_back(cur);
			cur = parent[cur];
		}
		reverse(path.begin(), path.end());
		for(int i : path)
			cout << i << " ";
	}
	else
		cout << "IMPOSSIBLE";
	cout << "\n";
	return 0;
}