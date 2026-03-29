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
        string s1 = "", s2 = "", res = "";
        char a, b;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> a >> b;
            s1 += a;
            s2 += b;
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        int carry = 0;
        for(int i = 0 ; i < m ; i++)
        {
            int n1 = s1[i] - '0', n2 = s2[i] - '0';
            int sum = n1 + n2 + carry;
            res += (sum % 10 + '0');
            carry = sum / 10;
        }
        if(carry) 
            res += (carry + '0');
        reverse(res.begin(), res.end());
        cout << res << "\n";
        if(t)
            cout << "\n";
    }

    return 0;
}