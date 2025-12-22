#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<string,string> language = {{"HELLO","ENGLISH"},{"HOLA","SPANISH"},{"HALLO","GERMAN"},
    {"BONJOUR","FRENCH"},{"CIAO","ITALIAN"},{"ZDRAVSTVUJTE","RUSSIAN"}};
    string s;
    int Case = 1;
    while(cin >> s && s != "#")
    {
        cout << "Case " << Case++ << ": ";
        cout << (language.count(s) ? language[s] : "UNKNOWN") << "\n";
    }
    return 0;
}