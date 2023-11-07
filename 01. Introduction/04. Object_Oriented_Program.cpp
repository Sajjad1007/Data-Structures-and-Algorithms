#include <iostream>

using namespace std;

class Rec
{
private:
    double l, b;

public:
    Rec(double l, double b)
    {
        this->l = l;
        this->b = b;
    }

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
    double l, b;
    cout << "Enter length and breadth : ";
    cin >> l >> b;

    Rec r(l, b);
    cout << "\nArea = " << r.area();
    cout << "\nPerimeter = " << r.peri() << "\n";
    return 0;
}

/*
Enter length and breadth : 10 5

Area = 50
Perimeter = 30
*/
