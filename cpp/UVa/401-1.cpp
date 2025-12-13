#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<string>
#include<unordered_map>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s, rev;
    unordered_map<char,char> mirror = 
    {
        {'E','3'},{'3','E'},{'L','J'},{'J','L'},
        {'Z','5'},{'5','Z'},{'S','2'},{'2','S'},
        {'A','A'},{'H','H'},{'I','I'},{'M','M'},
        {'O','O'},{'T','T'},{'U','U'},{'V','V'},
        {'W','W'},{'X','X'},{'Y','Y'},{'1','1'},
        {'8','8'}
    };
    while(cin >> s)
    {
        rev = s;
        bool mir = false, palin = false, valid = true;
        reverse(rev.begin(), rev.end());
        if(s == rev) 
            palin = true;
        for(char &c : rev)
        {
            if(mirror.count(c))
                c = mirror[c];
            else
            {
                valid = false;
                break;
            }
        }
        if(s == rev && valid)
            mir = true;
        cout << s;
        if(mir && palin)
            cout << " -- is a mirrored palindrome.\n\n";
        else if(mir) 
            cout << " -- is a mirrored string.\n\n";
        else if(palin)
            cout << " -- is a regular palindrome.\n\n";
        else
            cout << " -- is not a palindrome.\n\n";
    }
    return 0;
}