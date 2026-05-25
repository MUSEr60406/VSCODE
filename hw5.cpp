#include <iostream>
using namespace std;

void function3(int x)
{
    cout << "In function3\n";
    throw x;
}
void function2(int x)
{
    cout << "In function2\n";
    function3(x);
}

void function1(int x)
{
    cout << "In function1\n";
    function2(x);
}

int main()
{
    int x;
    cin >> x;

    try
    {
        cout << "In main" << endl;
        function1(x);
    }
    catch (int e)
    {
        cout << "Exception caught in main: " << e << endl;
    }

    return 0;
}