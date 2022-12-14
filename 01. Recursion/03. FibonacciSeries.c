/*
Fibonacci Series
0 1 1 2 3 5 8 13 ... nth term
0 1 2 3 4 5 6 7  ... n
*/

#include <stdio.h>

int count1;
int count2;

int fibo(int n) //time complexity is O(2^n)
{
    ++count1;
    if(n <= 1) return n;
    else{
        return fibo(n-2) + fibo(n-1);
    }
}

//This process is called "Memoization"
int mfibo(int n, int f[]) //time complexity is O(n)
{
    ++count2;
    if(n <= 1){
        f[n] = n;
        return f[n];
    }
    if(f[n-2] == -1) f[n-2] = mfibo(n-2, f);
    if(f[n-1] == -1) f[n-1] = mfibo(n-1, f);
    f[n] = f[n-2] + f[n-1];
    return f[n];
}

int main(void)
{
    int i, n;
    printf("Enter the value of n = ");
    scanf("%d", &n);

    int f[n];
    for(i = 0; i < n; ++i) f[i] = -1;

    printf("\n\nGeneral recursive function called...\n");
    printf("\n%dth term of the fibonacci series = %d\n", n, fibo(n));
    printf("Total function call = %d\n", count1);

    printf("\n\nMemoization recursive function called...\n");
    printf("\n%dth term of the fibonacci series = %d\n", n, mfibo(n, f));
    printf("Total function call = %d\n", count2);
    return 0;
}
