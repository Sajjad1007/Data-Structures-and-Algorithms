#include <iostream>

using namespace std;

double area(double l, double b)
{
    return l*b;
}

double peri(double l, double b)
{
    return 2*(l+b);
}

int main()
{
    double l, b;
    cout << "Enter length and breadth : ";
    cin >> l >> b;

    cout << "\nArea = " << area(l, b);
    cout << "\nPerimeter = " << peri(l, b) << "\n";
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
