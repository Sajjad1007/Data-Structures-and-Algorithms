#include <iostream>

using namespace std;

int main()
{
    double l, b;
    cout << "Enter length  : ";
    cin >> l;
    cout << "Enter breadth : ";
    cin >> b;

    double area = l*b;
    double perimeter = 2*(l+b);

    cout << "\nArea = " << area;
    cout << "\nPerimeter = " << perimeter << "\n";
    return 0;
}

/*
Enter length  : 10
Enter breadth : 5

Area = 50
Perimeter = 30
*/
