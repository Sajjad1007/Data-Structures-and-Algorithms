#include <iostream>

using namespace std;

double area(double l, double b)
{
    return l*b;
}

double perimeter(double l, double b)
{
    return 2*(l+b);
}

int main()
{
    double l, b;
    cout << "Enter length  : ";
    cin >> l;
    cout << "Enter breadth : ";
    cin >> b;

    cout << "\nArea = " << area(l, b);
    cout << "\nPerimeter = " << perimeter(l, b) << "\n";
    return 0;
}

/*
Enter length  : 10
Enter breadth : 5

Area = 50
Perimeter = 30
*/
