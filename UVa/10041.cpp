#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int r;
        vector<int> s(500, 0);
        cin >> r;
        for(int i = 0 ; i < r ; i++)
            cin >> s[i];
        sort(s.begin(), s.end());
        
    }

    return 0;
}