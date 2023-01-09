#include <stdio.h>

int count1;
int count2;

int power1(int base, int pow)
{
    ++count1;
    if(pow == 0) return 1;
    else{
        return base * power1(base, pow - 1);
    }
}

int power2(int base, int pow)
{
    ++count2;
    if(pow == 0) return 1;
    else if(pow % 2 == 0){
        return power2(base * base, pow / 2);
    }
    else{
        return base * power2(base * base, pow / 2);
    }
}

int main(void)
{
    int base, pow;
    printf("Enter base  = ");
    scanf("%d", &base);
    printf("Enter power = ");
    scanf("%d", &pow);

    printf("\n\nFirst  power function called...\n");
    printf("\n%d ^ %d = %d\n", base, pow, power1(base, pow));
    printf("Count = %d\n", count1);

    printf("\n\nSecond power function called...\n");
    printf("\n%d ^ %d = %d\n", base, pow, power2(base, pow));
    printf("Count = %d\n", count2);
    return 0;
}

/*
Enter base  = 3
Enter power = 15


First  power function called...

3 ^ 15 = 14348907
Count = 16


Second power function called...

3 ^ 15 = 14348907
Count = 5
*/
