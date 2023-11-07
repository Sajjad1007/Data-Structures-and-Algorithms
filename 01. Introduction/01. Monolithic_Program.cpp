#include <iostream>

using namespace std;

int main()
{
    double l, b;
    cout << "Enter length and breadth : ";
    cin >> l >> b;

    double area = l*b;
    double peri = 2*(l+b);

    cout << "\nArea = " << area;
    cout << "\nPerimeter = " << peri << "\n";
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
