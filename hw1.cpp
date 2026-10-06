#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int CharToInt(char c)
{
    if (c >= '0' && c <= '9') 
        return c - '0'; 
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))  
        return c - 'A' + 10;
}
char IntToChar(int x)
{
    if(x < 10)
        return '0' + x;
    
    return 'A' + x - 10;
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
    //
    N = a.substr(0, a.find('('));
    bool neg = false;
    if(N[0] == '-')
    {
        neg = true;
        N.erase(0, 1);
    }

    string interger = "", fraction = "";
    int dot = N.find('.');
    if(dot == string::npos)
        interger = N;
    else
    {
        interger = N.substr(0, dot);
        fraction = N.substr(dot + 1);
    }
    if(interger.empty())
        interger = "0";
    //int
    string INTans;
    int value = 0;
    for(char &c : interger)
        value = value * baseN + CharToInt(c);

    if(value == 0)
        INTans = "0";
    else
    {
        while(value > 0)
        {
            INTans += IntToChar(value % baseM);
            value /= baseM;
        }
        reverse(INTans.begin(), INTans.end());
    }
    if(dot == string::npos)
    {
        cout << INTans << "(" << baseM << ")";
        return 0;
    }
    //fraction
    string FRAans = "";
    int num = 0, den = 1; 
    for(char &c : fraction)
    {
        num = num * baseN + CharToInt(c);
        den *= baseN;
    }
    int pos = 0;
    unordered_map<int, int> check;
    while(num != 0 && pos < 20)
    {
        if(check.count(num))
        {
            int st = check[num];
            FRAans.insert(FRAans.begin() + st, '[');
            FRAans += ']';
            break;
        }
        num *= baseM;
        int digit = num / den;
        num %= den;
        FRAans += IntToChar(digit);
        pos++;
    }
    if(num != 0 && pos == 20)
        FRAans += "...";
    bool zero = (interger == "0" && fraction.empty());
    if(!fraction.empty())
    {
        bool fractionzero = true;
        for(char &c : fraction)
        {
            if(c != '0')
            {
                fractionzero = false;
                break;
            }
        }
        if(interger == "0" && fractionzero)
            zero = true;
    }
    if(zero)
        neg = false;
    if(neg)
        cout << "-";
    cout << INTans;
    if(!FRAans.empty())
        cout << "." << FRAans;
    cout << "(" << baseM << ")\n";
    return 0;
}