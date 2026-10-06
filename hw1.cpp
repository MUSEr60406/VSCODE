//s1141424
#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int CharToInt(char c)
{
    if (c >= '0' && c <= '9') 
        return c - '0'; 
    if (isalpha(c)) 
        return toupper(c) - 'A' + 10;
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
    string s, a, b, N;
    getline(cin, s);
    size_t arrow = s.find("->");
    if(arrow == string::npos)
    {
        cout << "ERROR: Invalid  Format\n";
        return 0;
    }
    a = s.substr(0, arrow), b = s.substr(arrow + 2);
    int baseM, baseN;
    //baseN
    size_t pos = a.find_last_of('(');
    if(pos == string::npos || a.back() != ')')
    {
        cout << "ERROR: Invalid format\n";
        return 0;
    }

    try
    {
        baseN = stoi(a.substr(pos + 1, a.length() - pos - 2));
    }
    catch(...)
    {
        cout << "ERROR: Invalid format\n";
        return 0;
    }
    //baseM
    if(b.empty() || b[0] != '(' || b.back() != ')')
    {
        cout << "ERROR: Invalid format\n";
        return 0;
    }
    try
    {
        baseM = stoi(a.substr(1, a.length() - 2));
    }
    catch(...)
    {
        cout << "ERROR: Invalid format\n";
        return 0;
    }
    if(baseN < 2 || baseN > 36 || baseM < 2 || baseM > 36)
    {
        cout << "ERROR: Base out of range\n";
        return 0;
    }
    //
    N = a.substr(0, pos);
    int dot_cnt = 0;
    for(char &c : N)
        if(c == '.')
            dot_cnt++;
    if(dot_cnt > 1)
    {
        cout << "ERROR: too many dots\n";
        return 0;
    }
    //
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
    if(interger.empty() && fraction.empty())
    {
        cout << "ERROR: Empty number\n";
        return 0;
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
    int poss = 0;
    unordered_map<int, int> check;
    while(num != 0 && poss < 20)
    {
        if(check.count(num))
        {
            int st = check[num];
            FRAans.insert(FRAans.begin() + st, '[');
            FRAans += ']';
            break;
        }
        check[num] = poss;
        num *= baseM;
        int digit = num / den;
        num %= den;
        FRAans += IntToChar(digit);
        poss++;
    }
    if(num != 0 && poss == 20)
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