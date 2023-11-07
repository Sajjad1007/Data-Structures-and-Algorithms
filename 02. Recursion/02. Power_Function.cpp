#include <iostream>

using namespace std;

int cnt1;
int cnt2;

int power1(int b, int p)
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

int power2(int b, int p)
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
    int b, p;
    cout << "Enter base and power = ";
    cin >> b >> p;

    cout << "\n1st power function called\n\n";
    cout << b << "^" << p << " = " << power1(b, p);
    cout << "\nTotal function calls = " << cnt1;

    cout << "\n\n2nd power function called\n\n";
    cout << b << "^" << p << " = " << power2(b, p);
    cout << "\nTotal function calls = " << cnt2 << "\n";
    return 0;
}

/*
Enter base and power = 3 15

1st power function called

3^15 = 14348907
Total function calls = 16

2nd power function called

3^15 = 14348907
Total function calls = 5
*/
