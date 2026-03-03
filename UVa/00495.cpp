#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
string f[5003];
string SUM(string s1, string s2)
{
    string S = "";
    int i = s1.length() - 1;
    int j = s2.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry > 0)
    {
        int n1 = (i >= 0) ? s1[i] - '0' : 0;
        int n2 = (j >= 0) ? s2[j] - '0' : 0;
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        S.push_back((sum % 10) + '0');
        i--, j--;
    }
    reverse(S.begin(), S.end());
    return S;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    f[0] = "0";
    f[1] = "1";
    for(int i = 2 ; i < 5003 ; i++)
        f[i] = SUM(f[i - 1], f[i - 2]);
    int n;
    while(cin >> n)
        cout << "The Fibonacci number for " << n << " is " << f[n] << "\n";

    return 0;
}