//Distinct Numbers
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<bool> numbers(1000000000, false);
	ll ans = 0, n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		if(!numbers[num])
		{
			ans++;
			numbers[num] = true;
		}
	}
	cout << ans;
	return 0;
}