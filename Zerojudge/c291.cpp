#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    char c;
    cin >> n1 >> c >> n2;

    switch (c)
    {
        case '+':
            cout << n1 + n2;
            break;
        case '-':
            cout << n1 - n2;
            break;
        case '*':
            cout << n1 * n2;
            break;
        case '/':
            cout << n1 / n2;
            break;
    }

    return 0;
}
