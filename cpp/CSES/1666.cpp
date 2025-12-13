//Buliding Roads
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int>> city;
vector<bool> visited;
vector<int> CITY; //每個連通量的其中一個城市
void bfs(int i)
{
	queue<int> q;
	q.push(i);
	visited[i] = true;
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		for(int i : city[now])
		{
			if(!visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	city.assign(n + 1, vector<int>());
	visited.assign(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		city[a].push_back(b);
		city[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			bfs(i); 
			CITY.push_back(i);
		}
	}
	cout << CITY.size() - 1 << "\n";
	for (int i = 0; i < CITY.size() - 1; i++)
		cout << CITY[i] << " " << CITY[i + 1] << "\n";
		return 0;
}