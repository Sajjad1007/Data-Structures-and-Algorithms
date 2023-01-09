#include <iostream>

using namespace std;

int main()
{
    double length, breadth;
    cout << "Enter length and breadth : ";
    cin >> length >> breadth;

    double area = length * breadth;
    double perimeter = 2 * (length + breadth);

    cout << "\nArea = " << area;
    cout << "\nPerimeter = " << perimeter;
    cout << '\n';
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
