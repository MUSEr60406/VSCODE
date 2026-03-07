#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int pow(int n, int p)
{
    int temp = 1;
    while(p--)
        temp *= n;
    return temp;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int D, I;
        cin >> D >> I;
        vector<bool> node((1 - pow(2,D)) / -1 + 1, false);
        for(int i = 1 ; i <= I ; i++)
        {
            int pos = 1, pre = 1;
            for(int j = 1 ; j <= D ; j++)
            {
                pre = pos;
                pos = (node[pos]) ? pos * 2 + 1 : pos * 2;
                node[pre] = !node[pre];
            }
            if(i == I - 1)
                cout << pos << "\n";
        }
    }

    return 0;
}