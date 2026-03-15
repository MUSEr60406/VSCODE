#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int s[500], r;
        cin >> r;
        for(int i = 0 ; i < r ; i++)
            cin >> s[i];

        for(int i = 0 ; i < r ; i++) //r - 1
        {
            for(int j = i + 1 ; j < r ; j++)
            {
                if(s[j] < s[i])
                    swap(s[i], s[j]);
            }
        }
        vector<int> v;

        int mid = (r - 1) / 2, total_dis = 0; //r - 1是因為index是0 ~ r - 1
        for(int i = 0 ; i < r ; i++)
            total_dis += abs(s[mid] - s[i]); //abs -> 絕對值

        cout << total_dis << "\n";
    }

    return 0;
}