#include<iostream>
using namespace std;
int ch[10000000][26], cnt[10000000], idx = 1;
void insert()
{
    string s;
    cin >> s;
    int p = 0; //root = 0
    for(auto i : s)
    {
        int j = i - 'a';
        if(!ch[p][j])
            ch[p][j] = idx++;
        p = ch[p][j];
    }
    cnt[p]++;
}
int check(string s)
{
    int p = 0;
    for(auto i : s)
    {
        int j = i - 'a';
        if(!ch[p][j])
            return 0;
        p = ch[p][j];
    }
    if(cnt[p] > 0)
    {
        cnt[p] = -1;
        return 1;
    }
    else  if(cnt[p] == -1)
        return -1;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
        insert();
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        int c = check(s);
        if(c == 0)
            cout << "WRONG\n";
        else if(c == 1)
            cout << "OK\n";
        else 
            cout << "REPEAT\n";
    }
    return 0;
}