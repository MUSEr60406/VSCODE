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
        vector<int> temp = {1};
        for(int i = 0 ; i < n.size() ; i++)
        {
            if(n[i] == '.')
            {
                decimal = n.size() - i - 1;
                continue;
            }
            number.push_back(n[i] - '0');
        }        
        for(int k = 0; k < power; k++) 
        {
            vector<int> next_temp(number.size() + temp.size() + 1, 0);
            for(int i = 0; i < number.size(); i++) 
            {
                for(int j = 0; j < temp.size(); j++) 
                {
                    next_temp[i + j] += number[i] * temp[j];
                    if (next_temp[i + j] >= 10) 
                    {
                        next_temp[i + j + 1] += next_temp[i + j] / 10;
                        next_temp[i + j] %= 10;
                    }
                }
            }
            while(next_temp.size() > 1 && next_temp.back() == 0) 
                next_temp.pop_back();
            temp = next_temp; 
        }
        for(int i = temp.size() - 1 ; i >= 0 ; i--)
        {
            cout << temp[i];
        }
    }

    return 0;
}