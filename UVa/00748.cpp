#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(getline(cin, s) && !s.empty())
    {
        int decimal = 0;
        stringstream ss(s);
        string number, power;
        while(ss >> number >> power)
        vector<int> num(100, 0);
        for(int i = 0 ; i < number.size() ; i++)
        {
            if(s[i] == '.')
            {
                decimal = number.size() - i;
                break;
            }
        }
        
    }

    return 0;
}