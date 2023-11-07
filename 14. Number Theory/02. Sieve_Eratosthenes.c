#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX 100000

bool status[MAX + 1];         //For a prime number x, status[x] = false.
int factor_cnt[MAX + 1];
int root = ceil(sqrt(MAX));

void init()
{
    for(int i = 1; i <= MAX; i++){
        factor_cnt[i] = 0;
    }
    return;
}

void sieve()
{
    int i, j;
    status[1] = true;

    for(i = 2; i <= root; i++){
        if(status[i] == false){
            for(j = i * i; j <= MAX; j += i){
                status[j] = true;
            }
        }
    }
    return;
}

void print_primes(int strt, int end)
{
    int i, cnt = 0;
    printf("\nPrime numbers from %d to %d :", strt, end);
    for(i = strt; i <= end; i++){
        if(status[i] == false){
            printf(" %d", i);
            cnt++;
        }
    }
    printf("\nTotal primes from %d to %d = %d", strt, end, cnt);
    return;
}

void prime_factors(int num)
{
    int i = 2;
    while(i <= num){
        if(status[i] == false){
            while(num % i == 0){
                factor_cnt[i]++;
                num /= i;
            }
            i++;
        }
        else{
            i++;
        }
    }
    return;
}

void print_factors(int num)
{
    int i, cnt = 0;
    for(i = 2; i <= num; i++){
        while(factor_cnt[i] != 0){
            printf(" %d", i);
            if(factor_cnt[i] == 1){
                cnt++;
            }
            factor_cnt[i]--;
        }
    }
    return;
}

void print_choice_list()
{
    printf("\nMenu\n");
    printf("1. Check prime\n");
    printf("2. Generate primes\n");
    printf("3. Prime factors\n");
    printf("4. Factorial factors\n");
    printf("5. Quit\n");
    return;
}

int main(void)
{
    int ch, num, strt, end;
    sieve();
    printf("Sieve Eratosthenes from 1 to %d has been initialized\n", MAX);

    while(true){
        print_choice_list();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter the number  : ");
                scanf("%d", &num);
                if(status[num]){
                    printf("\n%d is not a prime", num);
                }
                else{
                    printf("\n%d is a prime", num);
                }
                break;

            case 2:
                printf("Enter the lowest and highest number : ");
                scanf("%d %d", &strt, &end);
                print_primes(strt, end);
                break;

            case 3:
                printf("Enter the number  : ");
                scanf("%d", &num);
                init();
                prime_factors(num);
                printf("\nPrime factorization of %d :", num);
                print_factors(num);
                break;

            case 4:
                printf("Enter the factorial : ");
                scanf("%d!", &num);
                init();
                for(int i = 1; i <= num; i++){
                    prime_factors(i);
                }
                printf("\nPrime factorization of %d! :", num);
                print_factors(num);
                break;

            case 5:
                printf("\nFee Amanillah\n");
                return 0;

            default:
                printf("\nInvalid choice");
                break;
        }
        printf("\n");
    }
    return 0;
}

/*
Menu driven program
*/
