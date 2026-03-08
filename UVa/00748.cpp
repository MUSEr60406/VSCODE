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
        int decimal = 0, i = 0;
        vector<int> number(100, 0);
        while(i < n.size())
        {
            if(n[i] == '.')
            {
                decimal = n.size() - i - 1;
                i++;
            }
        }
        for(int &i : number)
            cout << i << " ";
        cout << "\n" << decimal;        
    }

    return 0;
}