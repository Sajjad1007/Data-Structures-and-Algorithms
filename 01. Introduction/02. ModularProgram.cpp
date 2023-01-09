#include <iostream>

using namespace std;

double getArea(double length, double breadth)
{
    double area = length * breadth;
    return area;
}

double getPerimeter(double length, double breadth)
{
    double peri = 2 * (length + breadth);
    return peri;
}

int main()
{
    double length, breadth;
    cout << "Enter length and breadth : ";
    cin >> length >> breadth;

    cout << "\nArea = " << getArea(length, breadth);
    cout << "\nPerimeter = " << getPerimeter(length, breadth);
    cout << '\n';
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
