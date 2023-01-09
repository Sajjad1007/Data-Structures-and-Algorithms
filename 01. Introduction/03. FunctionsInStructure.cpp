#include <iostream>

using namespace std;

struct rectangle{
    double length;
    double breadth;

    double getArea()
    {
        double area = length * breadth;
        return area;
    }

    double getPerimeter()
    {
        double perimeter = 2 * (length + breadth);
        return perimeter;
    }
};

int main()
{
    rectangle rec;
    cout << "Enter length and breadth : ";
    cin >> rec.length >> rec.breadth;

    cout << "\nArea = " << rec.getArea();
    cout << "\nPerimeter = " << rec.getPerimeter();
    cout << '\n';
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
