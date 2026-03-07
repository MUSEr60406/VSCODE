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
        int D, I, pos = 1;;
        cin >> D >> I;
        for(int i = 1 ; i <= D ; i++)
        {
            if(I % 2 == 0)
            {
                I /= 2;
                pos = pos * 2 + 1;
            }
            else
                I = I / 2 + 1;
                pos *= 2;
        }
        cout << pos / 2 << "\n";
    }

    return 0;
}