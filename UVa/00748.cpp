#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string n;
    int power;
    while(cin >> n >> power)
    {
        int decimal = 0, i = 0, j = 0;
        vector<int> number;
        vector<int> temp(100, 0);
        for(int i = 0 ; i < n.size() ; i++)
        {
            if(n[i] == '.')
            {
                decimal = n.size() - i - 1;
                continue;
            }
            number.push_back(n[i] - '0');
        }        

    }

    return 0;
}