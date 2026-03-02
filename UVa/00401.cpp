#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
bool isPalindrome(const string &s) 
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
bool isMirror(const string &s) 
{
    unordered_map<char, char> mir = 
    {
        {'A','A'}, {'E','3'}, {'H','H'}, {'I','I'}, {'J','L'},
        {'L','J'}, {'M','M'}, {'O','O'}, {'S','2'}, {'T','T'},
        {'U','U'}, {'V','V'}, {'W','W'}, {'X','X'}, {'Y','Y'},
        {'Z','5'}, {'1','1'}, {'2','S'}, {'3','E'}, {'5','Z'},
        {'8','8'}
    };
    int n = s.size();
    for(int i = 0; i < n; i++) {
        char c = s[i];
        char rc = s[n - 1 - i];
        if(!mir.count(c))
            return false;
        if(mir[c] != rc)
            return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);
    string s;
    while(cin >> s) {
        bool palin = isPalindrome(s);
        bool mirror = isMirror(s);
        if(palin && mirror)
            cout << s << " -- is a mirrored palindrome.\n\n";
        else if(palin)
            cout << s << " -- is a regular palindrome.\n\n";
        else if(mirror)
            cout << s << " -- is a mirrored string.\n\n";
        else
            cout << s << " -- is not a palindrome.\n\n";
    }
    return 0;
}
