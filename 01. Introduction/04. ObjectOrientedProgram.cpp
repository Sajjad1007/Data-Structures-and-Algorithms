#include <iostream>

using namespace std;

class Rectangle{

private:
    double length;
    double breadth;

public:
    Rectangle(double length, double breadth)
    {
        this->length = length;
        this->breadth = breadth;
    }

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
    double length, breadth;
    cout << "Enter length and breadth : ";
    cin >> length >> breadth;

    Rectangle rec(length, breadth);

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
