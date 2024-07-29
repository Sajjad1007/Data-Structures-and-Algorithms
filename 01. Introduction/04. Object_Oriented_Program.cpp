#include <iostream>

using namespace std;

class Rectangle
{
private:
    double l, b;

public:
    Rectangle(double l, double b)
    {
        this->l = l;
        this->b = b;
    }

    double area()
    {
        return l*b;
    }

    double perimeter()
    {
        return 2*(l+b);
    }
};

int main()
{
    double l, b;
    cout << "Enter length  : ";
    cin >> l;
    cout << "Enter breadth : ";
    cin >> b;

    Rectangle rec(l, b);
    cout << "\nArea = " << rec.area();
    cout << "\nPerimeter = " << rec.perimeter() << "\n";
    return 0;
}

/*
Enter length  : 10
Enter breadth : 5

Area = 50
Perimeter = 30
*/
