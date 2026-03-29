#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, m;
    cin >> t;
    while(t--)
    {
        cin >> m;
        string s1 = "", s2 = "";
        char a, b;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> a >> b;
            s1 += a;
            s2 += b;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for(int i = 0 ; i < m - 1 ; i++)
        {
            int n1 = s1[i] - '0', n2 = s2[i] - '0';
            int temp = n1 + n2;
            int carry = temp / 10;
            s1[i + 1] += 0 + (s1[i + 1] - '0' + carry);
        }
        reverse(s1.begin(), s1.end());
        cout << s1 << "\n";
        if(t)
            cout << "\n";
    }

    return 0;
}