#include <stdio.h>

int dim;

void input(int a[][dim]);
void output(int c[][dim]);
void sum(int a[][dim], int b[][dim], int c[][dim]);
void product(int a[][dim], int b[][dim], int c[][dim]);

int main(void)
{
    printf("Enter the dimension of the square matrices : ");
    scanf("%d", &dim);

    int a[dim][dim], b[dim][dim], c[dim][dim];

    printf("\nEnter 1st matrix\n");
    input(a);
    printf("\n1st matrix\n\n");
    output(a);

    printf("\nEnter 2nd matrix\n");
    input(b);
    printf("\n2nd matrix\n\n");
    output(b);

    sum(a, b, c);
    printf("\nSum of the matrices\n\n");
    output(c);
    product(a, b, c);
    printf("\nProduct of the matrices\n\n");
    output(c);
    return 0;
}

void input(int a[][dim])
{
    printf("\n");
    for(int row = 0; row < dim; ++row)
    {
        printf("row %d : ", row+1);
        for(int col = 0; col < dim; ++col)
        {
            scanf("%d", &a[row][col]);
        }
    }
    return;
}

void output(int c[][dim])
{
    for(int row = 0; row < dim; ++row)
    {
        for(int col = 0; col < dim; ++col)
        {
            printf("%2d ", c[row][col]);
        }
        printf("\n");
    }
    return;
}

void sum(int a[][dim], int b[][dim], int c[][dim])
{
    for(int row = 0; row < dim; ++row)
    {
        for(int col = 0; col < dim; ++col)
        {
            c[row][col] = a[row][col] + b[row][col];
        }
    }
    return;
}

void product(int a[][dim], int b[][dim], int c[][dim])
{
    for(int row = 0; row < dim; ++row)
    {
        for(int col = 0; col < dim; ++col)
        {
            c[row][col] = 0;
            for(int k = 0; k < dim; k++)
            {
                c[row][col] += a[row][k] * b[k][col];
            }
        }
    }
    return;
}

/*
Enter the dimension of the square matrices : 3

Enter 1st matrix

row 1 : 1 2 1
row 2 : 3 1 2
row 3 : 2 4 3

1st matrix

 1  2  1
 3  1  2
 2  4  3

Enter 2nd matrix

row 1 : 3 2 2
row 2 : 2 5 4
row 3 : 5 3 1

2nd matrix

 3  2  2
 2  5  4
 5  3  1

Sum of the matrices

 4  4  3
 5  6  6
 7  7  4

Product of the matrices

12 15 11
21 17 12
29 33 23
*/
