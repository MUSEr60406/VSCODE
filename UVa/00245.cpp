#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char c;
    list<string> l;
    string temp = "";
    int num = 0;
    while(cin.get(c))
    {
        if(isdigit(c))
        {
            if(num == 0 && c == '0')
                return 0;
            num = num * 10 + (c - '0');
        }
        else if(isalpha(c))
        {
            if(num != 0)
            {
                auto it = l.begin();
                for(int i = 0 ; i < num - 1 ; i++)
                    it++;
                string Temp = *it;
                l.erase(it);
                l.push_front(Temp);
                cout << Temp;
                num = 0;
            }
            temp += c;
        }
        else
        {
            if(num != 0)
            {
                auto it = l.begin();
                for(int i = 0 ; i < num - 1 ; i++)
                    it++;
                string Temp = *it;
                l.erase(it);
                l.push_front(Temp);
                cout << Temp;
                num = 0;
            }
            if(temp != "")
            {
                cout << temp;
                l.push_front(temp);
                temp = "";
            }
            cout << c;
        }
    }
    return 0;
}