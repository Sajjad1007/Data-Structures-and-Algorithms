#include<stdio.h>

int dim;

void readInput(int a[][dim]);
void writeOutput(int c[][dim]);
void computeSum(int a[][dim], int b[][dim], int c[][dim]);
void computeProduct(int a[][dim], int b[][dim], int c[][dim]);

int main(void)
{
    printf("Enter the dimension of the square matrices : ");
    scanf("%d", &dim);

    int a[dim][dim], b[dim][dim], c[dim][dim];

    printf("\n\nEnter 1st matrix :\n");
    readInput(a);
    printf("\n1st matrix :\n\n");
    writeOutput(a);

    printf("\n\nEnter 2nd matrix :\n");
    readInput(b);
    printf("\n2st matrix :\n\n");
    writeOutput(b);

    computeSum(a, b, c);
    printf("\n\nSums of the matrices :\n\n");
    writeOutput(c);
    computeProduct(a, b, c);
    printf("\nProduct of the matrices :\n\n");
    writeOutput(c);
    return 0;
}

void readInput(int a[][dim])
{
    printf("\n");
    for(int row = 0; row < dim; ++row){
        printf("Enter data for row %d : ", row+1);

        for(int col = 0; col < dim; ++col){
            scanf("%d", &a[row][col]);
        }
    }
    return;
}

void writeOutput(int c[][dim])
{
    for(int row = 0; row < dim; ++row){
        for(int col = 0; col < dim; ++col){
            printf("%3d", c[row][col]);
        }
        printf("\n");
    }
    return;
}

void computeSum(int a[][dim], int b[][dim], int c[][dim])
{
    for(int row = 0; row < dim; ++row){
        for(int col = 0; col < dim; ++col){
            c[row][col] = a[row][col] + b[row][col];
        }
    }
    return;
}

void computeProduct(int a[][dim], int b[][dim], int c[][dim])
{
    for(int row = 0; row < dim; ++row){
        for(int col = 0; col < dim; ++col){
            c[row][col] = 0;
            for(int k = 0; k < dim; k++){
                c[row][col] += a[row][k] * b[k][col];
            }
        }
    }
    return;
}
