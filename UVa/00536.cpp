#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
void f(string pre, string in)
{
    if(pre.empty())
        return;
    char root = pre[0];
    int pos = in.find(root);
    string
    preL = pre.substr(1, pos),
    preR = pre.substr(pos + 1, pos),
    inL = in.substr(0, pos),
    inR = in.substr(pos + 1, pos);
    f(preL, inL);
    f(preR, inR);
    cout << root;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string pre, in;
    while(cin >> pre >> in)
    {
        f(pre, in);
        cout << "\n";
    }
    return 0;
}