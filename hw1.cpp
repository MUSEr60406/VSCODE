#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int CharToInt(char c)
{
    if (c >= '0' && c <= '9') return c - '0'; 
    if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
}

char IntToChar(int x)
{
    if(x < 10)
        return '0' + x;
    
    return 'A' + x - 10;
}  

int to10(string s, int base)
{
    int x = 0;
    for(char &c : s)
        x = x * base + CharToInt(c);
    return x;
}

string from10(int x, int base)
{
    if(x == 0)
        return "0";
    string res = "";
    while(x > 0)
    {
        res += IntToChar(x % base);
        x /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, a, arrow, b, N;
    getline(cin, s);
    stringstream ss(s);
    int baseM, baseN;
    ss >> a >> arrow >> b;
    baseN = stoi(a.substr(a.find('(') + 1, a.find(')') - 1));
    baseM = stoi(b.substr(b.find('(') + 1, b.find(')') - 1));
    cout << baseN << " " << baseM << "\n";
    //
    N = a.substr(0, a.find('('));
    bool neg = true;
    if(N[0] == '-')
    {
        neg = true;
        N.erase(0, 1);
    }
    string interger = N.substr(0, N.find('.'));
    string fraction = N.substr(N.find('.') + 1);
    cout << interger << " " << fraction;
    if(interger.empty())
        interger = "0";
    //
    return 0;
}