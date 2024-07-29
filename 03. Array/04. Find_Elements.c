#include <stdio.h>
#include <stdbool.h>

typedef struct array
{
    int p[20];
    int size;
} array;

array arr;
int i, max, min;

void input()
{
    printf("Number of elements : ");
    scanf("%d", &arr.size);
    printf("Enter the elements : ");
    for(i = 0; i < arr.size; i++)
    {
        scanf("%d", &arr.p[i]);
    }
    return;
}

void max_min()
{
    max = min = arr.p[0];
    for(i = 1; i < arr.size; i++)
    {
        if(arr.p[i] > max)
        {
            max = arr.p[i];
        }
        else if(arr.p[i] < min)
        {
            min = arr.p[i];
        }
    }
    return;
}

void missing_elements()
{
    max_min();
    int hash[max+1];

    if(min != max-(arr.size-1))
    {
        printf("\nMissing elements from %d to %d :", min, max);
    }
    else
    {
        printf("\nNo elements are missing from %d to %d.\n", min, max);
        return;
    }

    for(i = min; i <= max; i++)
    {
        hash[i] = 0;
    }
    for(i = 0; i < arr.size; i++)
    {
        hash[arr.p[i]] = 1;
    }
    for(i = min; i <= max; i++)
    {
        if(hash[i] == 0)
        {
            printf(" %d", i);
        }
    }
    printf("\n");
    return;
}

void duplicate_elements()
{
    max_min();
    bool printed = false;
    int hash[max+1];

    for(i = min; i <= max; i++)
    {
        hash[i] = 0;
    }
    for(i = 0; i < arr.size; i++)
    {
        hash[arr.p[i]]++;
    }
    for(i = min; i <= max; i++)
    {
        if(hash[i] > 1 && !printed)
        {
            printed = true;
            printf("\nDuplicate elements :");
            printf(" %d (%d times) ", i, hash[i]);
        }
        else if(hash[i] > 1)
        {
            printf(" %d (%d times) ", i, hash[i]);
        }
    }
    if(!printed)
    {
        printf("\nNo duplicate elements found.");
    }
    printf("\n");
    return;
}

void find_pairs()
{
    bool printed = false;
    max_min();
    int sum, hash[max+1];
    printf("Enter sum = ");
    scanf("%d", &sum);

    for(i = min; i <= max; i++)
    {
        hash[i] = 0;
    }
    for(i = 0; i < arr.size; i++)
    {
        if(hash[sum-arr.p[i]] == 1 && !printed)
        {
            printed = true;
            printf("\nThe pairs are :");
            int min = (arr.p[i] < sum-arr.p[i]) ? arr.p[i] : sum-arr.p[i];
            printf(" (%d, %d)", min, sum-min);         // Print the smaller element first.
        }
        else if(hash[sum-arr.p[i]] == 1)
        {
            int min = (arr.p[i] < sum-arr.p[i]) ? arr.p[i] : sum-arr.p[i];
            printf(" (%d, %d)", min, sum-min);
        }
        hash[arr.p[i]] = 1;
    }

    if(!printed)
    {
        printf("\nNo pairs found.");
    }
    printf("\n");
    return;
}

void choice_list()
{
    printf("Menu\n");
    printf("1. Define\n");
    printf("2. Find missing elements\n");
    printf("3. Find duplicate elements\n");
    printf("4. Find pairs\n");
    printf("5. Quit\n");
    return;
}

void display()
{
    printf("\nThe array :");
    for(i = 0; i < arr.size; i++)
    {
        printf(" %d", arr.p[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int ch;

    while(true)
    {
        choice_list();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                input();
                display();
                break;

            case 2:
                missing_elements();
                break;

            case 3:
                duplicate_elements();
                break;

            case 4:
                find_pairs();
                break;

            case 5:
                printf("\nFee Amanillah\n");
                return 0;

            default:
                printf("\nInvalid choice\n");
                break;
        }
        printf("\n");
    }
}

/*
Menu driven program
*/
