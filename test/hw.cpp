#include <iostream>
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

    Complex operator*(const Complex &other) const
    {
        return
        {
            real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary + other.real
        };
    }

    bool operator==(const Complex &other) const
    {
        return (real == other.real && imaginary == other.imaginary);
    }

    bool operator!=(const Complex &other) const
    {
        return !(*this != other);
    }

    friend istream &operator>>(istream &in, Complex &c)
    {
        in >> c.real >> c.imaginary;
        return in;
    }

   friend ostream &operator<<(ostream &out, const Complex &c)
   {
        out << c.real;
        double i = abs(c.imaginary);
        out << (c.imaginary >= 0 ? " + " : " - ") << i << "i";
        return out;
    }
};

int main()
{
    Complex c1, c2;

    cin >> c1 >> c2;

    cout << "Complex1: " << c1 << endl;
    cout << "Complex2: " << c2 << endl;
    cout << "Product: " << (c1 * c2) << endl;
    cout << "Equal: " << (c1 == c2 ? "True" : "False") << endl;
    cout << "Not Equal: " << (c1 != c2 ? "True" : "False") << endl;

    return 0;
}