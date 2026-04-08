#include<iostream>
using namespace std;
class c
{
    private:
        static int s;
    public:
        c (int i = 0)
        {
            s = i;
        }
        static void f(int a)
        {
            s = a;
        }
        friend ostream &operator<<(ostream &out, c &C)
        {
            cout << C.s << "\n";
            return out;
        }
};
int main()
{
    c A(1), B;
    cout << A << B;
    A.f(5);
    cout << B;
}