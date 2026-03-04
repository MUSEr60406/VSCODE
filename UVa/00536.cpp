#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
void f(string front, string middle)
{
    char root = front[0];
    for(int i = 0 ; i < middle.size() ; i++)
    {
        if(middle[i] == root)
        {
            if(i != 0) //代表有左子樹
                f(front.substr(1, i), middle.substr(0, i));
            if(i != middle.size() - 1) //代表有右子樹
                f(front.substr(i + 1, front.size() - 1 - i), middle.substr(i + 1, front.size() - i - 1));
            cout << root;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string front, middle;
    while(cin >> front >> middle)
    {
        f(front, middle);
        cout << "\n";
    }

    return 0;
}