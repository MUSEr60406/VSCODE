#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle
{
    private:
        double length = 1, width = 1;
    Rectangle(double l, double w)
    {
        setL(l);
        setW(w);
    }
    void setL(double l)
    {
        if(l > 0 && l < 20.0)
            length = l;
    }
    void setW(double w)
    {
        if(w > 0 && w < 20.0)
            width = w;
    }
    //
    double getLength() const
    {
        return length;
    }
    double getWidth() const
    {
        return width;
    }
    double perimeter() const
    {
        return (length + width) * 2;
    }
    double area() const
    {
        return length * width;
    }
};

int main()
{
    double length, width;
    cin >> length >> width;

    Rectangle rect(length, width);

    cout << fixed << setprecision(2);
    cout << "Length: " << rect.getLength() << endl;
    cout << "Width: " << rect.getWidth() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;
    cout << "Area: " << rect.area() << endl;

    return 0;
}