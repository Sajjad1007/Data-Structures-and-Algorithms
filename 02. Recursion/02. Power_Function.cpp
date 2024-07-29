#include <iostream>

using namespace std;

int cnt1, cnt2;

double power1(double b, int p)
{
    ++cnt1;

    if(p == 0)
    {
        return 1;
    }
    else
    {
        return b*power1(b, p-1);
    }
}

double power2(double b, int p)
{
    ++cnt2;

    if(p == 0)
    {
        return 1;
    }
    else if(p%2 == 0)
    {
        return power2(b*b, p/2);
    }
    else
    {
        return b*power2(b*b, p/2);
    }
}

int main()
{
    int p;
    double b;
    cout << "Enter base  : ";
    cin >> b;
    cout << "Enter power : ";
    cin >> p;
    double base = (p > 0) ? b : 1/b;
    int pow = abs(p);

    cout << "\n1st power function called\n\n";
    cout << b << "^" << p << " = " << power1(base, pow);
    cout << "\nTotal function calls = " << cnt1;

    cout << "\n\n2nd power function called\n\n";
    cout << b << "^" << p << " = " << power2(base, pow);
    cout << "\nTotal function calls = " << cnt2 << "\n";
    return 0;
}

/*
Enter base  : 3
Enter power : 15

1st power function called

3^15 = 14348907
Total function calls = 16

2nd power function called

3^15 = 14348907
Total function calls = 5
*/
