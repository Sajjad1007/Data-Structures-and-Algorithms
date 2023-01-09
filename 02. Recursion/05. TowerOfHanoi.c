#include <stdio.h>

int count;
int steps;

//Time complexity is O(2^n)
void towerOfHanoi(int n, char a, char b, char c)
{
    ++count;
    if(n > 0){
        towerOfHanoi(n - 1, a, c, b);
        printf("Move from %c to %c\n", a, c);
        ++steps;
        towerOfHanoi(n - 1, b, a, c);
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

/*
How many disks ? 3

Move from A to C
Move from A to B
Move from C to B
Move from A to C
Move from B to A
Move from B to C
Move from A to C

Total function call = 15
Total steps = 7
*/
