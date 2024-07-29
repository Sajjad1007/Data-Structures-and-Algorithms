#include <iostream>

using namespace std;

struct rectangle
{
    double l, b;

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
    rectangle rec;
    cout << "Enter length  : ";
    cin >> rec.l;
    cout << "Enter breadth : ";
    cin >> rec.b;

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
