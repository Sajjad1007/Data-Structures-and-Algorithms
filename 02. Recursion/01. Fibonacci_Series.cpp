/*
Fibonacci Series
0 1 1 2 3 5 8 13 ... nth term
1 2 3 4 5 6 7 8  ... n
*/

#include <iostream>

#define MAX 50

using namespace std;

int cnt;

int fibo(int n)          //Time complexity is O(2^n).
{
    ++cnt;
    if(n <= 2)
    {
        return n-1;
    }
    else
    {
        return fibo(n-2) + fibo(n-1);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;
    printf("\n%dth term of the fibonacci series = %d\n", n, fibo(n));
    cout << "Total function calls = " << cnt << "\n";
    return 0;
}

/*
Enter the value of n = 20

20th term of the fibonacci series = 4181
Total function calls = 13529
*/
