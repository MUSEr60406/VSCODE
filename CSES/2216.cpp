//Collecting Numbers
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, rounds;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		v[x] = i;
	}
	for (int i = 2; i <= n; i++)
	{
		if(v[i] < v[i-1])
			rounds++;
	}
	cout << rounds;
	return 0;
}