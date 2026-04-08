#include<iostream>
using namespace std;

class c
{
    private:
        static int s; // 宣告
    public:
        c (int i = 0)
        {
            s = i;
        }
        static void f(int a)
        {
            s = a;
        }
        // 修正：使用 out 而非 cout
        friend ostream &operator<<(ostream &out, c &C)
        {
            cout << C.s << "\n";
            return out;
        }
};

// 修正：必須在類別外定義並分配記憶體
int c::s = 0; 

int main()
{
    c A(1), B;     // A 讓 s=1, B 接著讓 s=0
    cout << A << B; // 都會輸出 0
    A.f(5);        // 透過 A 修改 s 為 5
    cout << B;     // B 看到的 s 也變成了 5
    return 0;
}