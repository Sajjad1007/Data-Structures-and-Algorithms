#include <stdio.h>

int count;

int C(int n, int r)
{
    ++count;
    if(r == 0 || n == r) return 1;
    else{ //(n+1)Cr = nCr + nC(r-1)
        return C(n-1, r) + C(n-1, r-1);
    }
}

int main(void)
{
    int n, r;
    printf("Enter the value of n and r\n");
    printf("n = ");
    scanf("%d", &n);
    printf("r = ");
    scanf("%d", &r);

    if(n < r){
        printf("\nn cannot be less than r\n");
        return 1;
    }
    printf("\n%dC%d = %d\n", n, r, C(n, r));
    printf("Total function call = %d\n", count);
    return 0;
}
