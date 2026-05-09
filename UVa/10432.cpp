#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pi 3.14159265358979323846
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    double r, n;
    while(cin >> r >> n)
    {
        double angle = 360 / n, a = 0;
        a = 1/2 * r * r * sin(angle * pi / 180) * n;
        cout << fixed << setprecision(3) << a << "\n";
    }

    return 0;
}