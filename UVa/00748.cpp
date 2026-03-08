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
        vector<int> number(100, 0);
        while(i < n.size() || j < n.size())
        {
            if(n[j] == '.')
            {
                decimal = n.size() - j - 1;
                j++;
            }
            number[i] = n[j] - '0';
            i++, j++;
        }
        for(int &i : number)
            cout << i << " ";
        cout << "\n" << decimal;        
    }

    return 0;
}