#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    cin.ignore();
    string s;
    while(t--)
    {   
        getline(cin, s);
        if(s[0] == ' ')
        {
            cout  << "Yes\n";
            continue;
        }
        vector <bool> visited(128,false);
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ')')
            {
                for(int j = i - 1 ; j >= 0 ; j--)
                {
                    if(s[j] == '(' && visited[j] == false)
                    {
                        visited[i] = true;
                        visited[j] = true;
                        break;
                    }
                }
            }
            else if(s[i] == ']')
            {
                for(int j = i - 1; j >= 0 ; j--)
                {
                    if(s[j] == '[' && visited[j] == false)
                    {
                        visited[i] = true;
                        visited[j] = true;
                        break;
                    }
                }
            }
        }
        bool correct = true;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(visited[i] == false && (s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']'))
            {
                correct = false;
                break;
            }
        }
        if(correct)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}