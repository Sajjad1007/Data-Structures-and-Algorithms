#include <stdio.h>

int count;
int steps;

//Time complexity O(2^n)
void towerOfHanoi(int n, char a, char b, char c)
{
    ++count;
    if(n > 0){
        towerOfHanoi(n-1, a, c, b);
        printf("Move from %c to %c\n", a, c);
        ++steps;
        towerOfHanoi(n-1, b, a, c);
    }
    return;
}

int main(void)
{
    int n;
    printf("How many disks ? ");
    scanf("%d", &n);
    printf("\n");
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("\nTotal function call = %d", count);
    printf("\nTotal steps = %d\n", steps);
    return 0;
}
