#include <iostream>
#include <cmath> // 用於 abs()
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0)
        : real(r), imaginary(i)
    {
    }

    // 1. 多載乘法運算子 (*)
    // 公式: (a+bi)*(c+di) = (ac-bd) + (ad+bc)i
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real
        );
    }

    // 2. 多載等於運算子 (==)
    bool operator==(const Complex& other) const {
        return (real == other.real && imaginary == other.imaginary);
    }

    // 3. 多載不等於運算子 (!=)
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // 4. 多載輸入運算子 (>>)
    // 必須定義為 friend 才能讓 cin 放在左邊
    friend istream& operator>>(istream& in, Complex& c) {
        in >> c.real >> c.imaginary;
        return in;
    }

    // 5. 多載輸出運算子 (<<)
    // 需根據虛部正負調整顯示格式
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imaginary >= 0) {
            out << " + " << c.imaginary << "i";
        } else {
            // 當虛部為負時，使用 "-" 並取絕對值顯示
            out << " - " << abs(c.imaginary) << "i";
        }
        return out;
    }
};

int main()
{
    Complex c1, c2;

    // 測試輸入
    if (!(cin >> c1 >> c2)) return 0;

    // 測試輸出與各種運算子
    cout << "Complex1: " << c1 << endl;
    cout << "Complex2: " << c2 << endl;
    cout << "Product: " << (c1 * c2) << endl;
    cout << "Equal: " << (c1 == c2 ? "True" : "False") << endl;
    cout << "Not Equal: " << (c1 != c2 ? "True" : "False") << endl;

    return 0;
}