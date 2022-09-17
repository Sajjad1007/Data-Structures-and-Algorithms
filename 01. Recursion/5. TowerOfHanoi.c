#include <stdio.h>

int count;
int steps;

//time complexity O(2^n)
void TOH(int n, char a, char b, char c)
{
    ++count;
    if(n > 0){
        TOH(n-1, a, c, b);
        printf("Move from %c to %c\n", a, c);
        ++steps;
        TOH(n-1, b, a, c);
    }
    return;
}

int main(void)
{
    int n;
    printf("How many disks ? ");
    scanf("%d", &n);
    printf("\n");
    TOH(n, 'A', 'B', 'C');
    printf("\nTotal function call = %d", count);
    printf("\nTotal steps = %d\n", steps);
    return 0;
}
