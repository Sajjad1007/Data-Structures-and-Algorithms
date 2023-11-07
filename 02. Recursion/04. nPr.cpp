#include <iostream>

using namespace std;

int cnt;

int fact(int n)
{
    ++cnt;
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}

int main()
{
    int n, r;
    cout << "Enter the value of n and r : ";
    cin >> n >> r;

    if(n < r)
    {
        cout << "\nn cannot be less than r\n";
        exit(1);
    }
    else
    {
        int ans = fact(n)/fact(n-r);
        printf("\n%dP%d = %d\n", n, r, ans);
        printf("Total function calls = %d\n", cnt);
        exit(0);
    }
}

/*
Enter the value of n and r : 10 5

10P5 = 30240
Total function calls = 15
*/
