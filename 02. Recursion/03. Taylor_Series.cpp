/*
Taylor Series
e ^ x = 1 + (x ^ 1 / 1!) + (x ^ 2 / 2!) + (x ^ 3 / 3!) + ... n terms
Horner's rule
e ^ x = 1 + (x / 1){1 + (x / 2){1 + (x / 3){... n terms}}}
*/

#include <iostream>

using namespace std;

// For general rule, time complexity is O(n).
int cnt1 = 0;

double e(int x, int n)
{
    double sum;
    static double pow = 1, fact = 1;

    if(n == 0)
    {
        return 1;
    }
    else
    {
        sum = e(x, n-1);
        ++cnt1;
        pow *= x;             // x to the power pow
        ++cnt1;
        fact *= n;            // n factorial
        return (pow/fact)+sum;
    }
}

// For Horner's rule, time complexity is O(n).
int cnt2 = 0;

double e_horner(int x, int n)
{
    static double sum = 1;

    if(n == 0)
    {
        return sum;
    }
    else
    {
        ++cnt2;
        sum = 1+(x*sum/n);
        return e_horner(x, n-1);
    }
}

int main()
{
    int x, n;
    cout << "Enter power of e : ";
    cin >> x;
    cout << "Enter number of terms : ";
    cin >> n;

    cout << "\nGeneral  rule : ";
    printf("e^%d = %.2lf\n", x, e(x, n));
    cout << "Total multiplications = " << cnt1;
    cout << "\n\nHorner's rule : ";
    printf("e^%d = %.2lf\n", x, e_horner(x, n));
    cout << "Total multiplications = " << cnt2 << "\n";
    return 0;
}

/*
Enter power of e : 8
Enter number of terms : 30

General  rule : e^8 = 2980.96
Total multiplications = 60

Horner's rule : e^8 = 2980.96
Total multiplications = 30
*/
