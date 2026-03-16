#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
        cout << n << " is " << (n % 11 == 0 ? "" : "not ") << "a multiple of 11.\n";
    return 0;
}