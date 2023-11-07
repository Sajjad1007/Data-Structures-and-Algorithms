#include <iostream>

using namespace std;

struct rec
{
    double l, b;

    double area()
    {
        return l*b;
    }

    double peri()
    {
        return 2*(l+b);
    }
};

int main()
{
    rec r;
    cout << "Enter length and breadth : ";
    cin >> r.l >> r.b;

    cout << "\nArea = " << r.area();
    cout << "\nPerimeter = " << r.peri() << "\n";
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
