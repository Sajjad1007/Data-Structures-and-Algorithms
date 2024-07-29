#include <iostream>

#define MAX 30

using namespace std;

int cnt;
int C[MAX][MAX];

int nCr(int n, int r)
{
    ++cnt;

    if(r == 0 || n == r)
    {
        C[n][r] = 1;
    }
    else if(C[n][r] == 0)
    {
        C[n-1][r] = nCr(n-1, r);
        C[n-1][r-1] = nCr(n-1, r-1);
        C[n][r] =  C[n-1][r]+C[n-1][r-1];       // (n+1)Cr = nCr + nC(r-1)
    }
    return C[n][r];
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
        int ans = nCr(n, r);
        printf("\n%dC%d = %d\n", n, r, ans);
        printf("Total function calls = %d\n", cnt);
        exit(0);
    }
}

/*
Enter n : 10
Enter r : 5

10C5 = 252
Total function calls = 51
*/
