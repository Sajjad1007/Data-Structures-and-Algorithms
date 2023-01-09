/*
Taylor Series
e ^ x = 1 + (x ^ 1 / 1!) + (x ^ 2 / 2!) + (x ^ 3 / 3!) + ... n terms
Horner's rule
e ^ x = 1 + (x / 1){1 + (x / 2){1 + (x / 3){... n terms}}}
*/

#include <stdio.h>

//For general rule, time complexity is O(n)
int count1 = 0;

double e(int x, int n)
{
    static double pow = 1, fact = 1;
    double sum;

    if(n == 0) return 1;
    else{
        sum = e(x, n - 1);
        ++count1;
        pow *= x; //x to the power p
        ++count1;
        fact *= n; //n factorial
        return (pow / fact) + sum;
    }
}

//For Horner's rule, time complexity is O(n)
int count2 = 0;

double e_Horner(int x, int n)
{
    static double sum = 1;

    if(n == 0) return sum;
    else{
        ++count2;
        sum = 1 + x * sum / n;
        return e_Horner(x, n - 1);
    }
}

int main(void)
{
    int x, n;
    printf("Enter power of e = ");
    scanf("%d", &x);
    printf("Enter number of terms : ");
    scanf("%d", &n);

    printf("\nGeneral  rule : ");
    printf("e ^ %d = %.2lf\n", x, e(x, n));
    printf("Total multiplications = %d\n", count1);
    printf("\nHorner's rule : ");
    printf("e ^ %d = %.2lf\n", x, e_Horner(x, n));
    printf("Total multiplications = %d\n", count2);
    return 0;
}

/*
Enter power of e = 8
Enter number of terms : 30

General  rule : e ^ 8 = 2980.96
Total multiplications = 60

Horner's rule : e ^ 8 = 2980.96
Total multiplications = 30
*/
