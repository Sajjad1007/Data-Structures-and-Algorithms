#include <iostream>

#define MAX 30

using namespace std;

int cnt;
int fact[MAX];

int factorial(int n)
{
    ++cnt;

    if(n == 1)
    {
        fact[n] = 1;
    }
    else if(fact[n] == 0)
    {
        fact[n] = n*factorial(n-1);
    }
    return fact[n];
}

int main()
{
    int n, r;
    cout << "Enter n : ";
    cin >> n;
    cout << "Enter r : ";
    cin >> r;

    if(n < r)
    {
        cout << "\nn cannot be less than r.\n";
        exit(1);
    }
    else
    {
        int ans = factorial(n)/factorial(n-r);
        printf("\n%dP%d = %d\n", n, r, ans);
        printf("Total function calls = %d\n", cnt);
        exit(0);
    }
}

/*
Enter n : 10
Enter r : 5

10P5 = 30240
Total function calls = 11
*/
