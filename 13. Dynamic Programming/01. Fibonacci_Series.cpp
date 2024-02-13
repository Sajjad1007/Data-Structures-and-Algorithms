/*
The process of saving subproblem results is called 'Memoization'.

Fibonacci Series
0 1 1 2 3 5 8 13 ... nth term
1 2 3 4 5 6 7 8  ... n
*/

#include <iostream>
#include <cstring>

#define MAX 50
#define EMPTY -1

using namespace std;

int dp[MAX+1];
int mcnt, tcnt;

// Memoization
int mfibo(int n)         // Time complexity is O(n).
{
    ++mcnt;
    if(n <= 2)
    {
        dp[n] = n-1;
    }
    else if(dp[n] == EMPTY)
    {
        dp[n-1] = mfibo(n-1);
        dp[n-2] = mfibo(n-2);
        dp[n] = dp[n-1]+dp[n-2];
    }
    return dp[n];
}

// Tabulation
int tfibo(int n)         // Time complexity is O(1).
{
    ++tcnt;
    int i, prev = 0, curr = 1, next;

    if(n <= 2)
    {
        return n-1;
    }
    else
    {
        for(i = 3; i <= n; i++)
        {
            next = prev+curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
}

int main()
{
    int n;
    cout << "Enter the value of n = ";
    cin >> n;
    memset(dp, EMPTY, sizeof(dp));

    cout << "\nMemoization\n";
    printf("\n%dth term of the fibonacci series = %d\n", n, mfibo(n));
    cout << "Total function calls = " << mcnt;

    cout << "\n\nTabulation\n";
    printf("\n%dth term of the fibonacci series = %d\n", n, tfibo(n));
    cout << "Total function calls = " << tcnt << "\n";
    return 0;
}

/*
Enter the value of n = 20

Memoization

20th term of the fibonacci series = 4181
Total function calls = 37

Tabulation

20th term of the fibonacci series = 4181
Total function calls = 1
*/
