#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int pow(int n, int p)
{
    int temp = 1;
    while(p--)
        temp *= n;
    return temp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int d, i;
        cin >> d >> i;
        vector<int> node((1 - pow(2,d)) / -1 + 1, false);
        
    }

    return 0;
}