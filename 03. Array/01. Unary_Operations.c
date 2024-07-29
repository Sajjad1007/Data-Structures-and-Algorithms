#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct array
{
    int *p;
    int size;
    int capacity;
} array;

array arr;

void input()
{
    int n, i;
    printf("Array capacity : ");
    scanf("%d", &arr.capacity);
    arr.p = (int *)malloc(arr.capacity*sizeof(int));
    arr.size = 0;

    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr.p[i]);
        arr.size++;
    }
    return;
}

void Insert()
{
    int i, pos, val;
    printf("Enter the position : ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= arr.size+1)
    {
        printf("Enter an element : ");
        scanf("%d", &val);

        int indx = pos-1;               // position = index + 1
        for(i = arr.size; i > indx; i--)
        {
            arr.p[i] = arr.p[i-1];
        }
        arr.p[indx] = val;
        arr.size++;
    }
    return;
}

void Delete()
{
    int i, pos;
    printf("Enter the position : ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= arr.size)
    {
        int indx = pos-1;
        for(i = indx; i < arr.size-1; i++)
        {
            arr.p[i] = arr.p[i+1];
        }
        arr.size--;
    }
    return;
}

void update()
{
    int pos, val;
    printf("Enter the position : ");
    scanf("%d", &pos);

    if(pos >= 1 && pos <= arr.size)
    {
        printf("Enter an element : ");
        scanf("%d", &val);
        arr.p[pos-1] = val;
    }
    return;
}

void reverse()
{
    int i, j, temp;
    for(i = 0, j = arr.size-1; i < j; i++, j--)
    {
        temp = arr.p[i];
        arr.p[i] = arr.p[j];
        arr.p[j] = temp;
    }
    return;
}

// This functions rearranges all the negatives to the left and all the positives to the right.
void rearrange()
{
    int i = 0;
    int j = arr.size-1;

    while(i < j)
    {
        while(arr.p[i] < 0)
        {
            i++;
        }
        while(arr.p[j] > 0)
        {
            j--;
        }

        if(i < j)
        {
            int temp = arr.p[i];
            arr.p[i] = arr.p[j];
            arr.p[j] = temp;
        }
    }
    return;
}

void left_rotation()
{
    int i, j, n;
    printf("Number of elements to rotate : ");
    scanf("%d", &n);
    n %= arr.size;
    int *r = (int *)malloc(n*sizeof(int));        // Create dynamic array to store rotating elements.

    if(n >= 1 && n <= arr.size)
    {
        for(i = 0; i < n; i++)
        {
            r[i] = arr.p[i];                      // Store rotating elements in that dynamic array.
        }
        for(i = 0; i < arr.size-n; i++)
        {
            arr.p[i] = arr.p[i+n];                // Shift the elements towards left.
        }
        for(i = arr.size-n, j = 0; i < arr.size; i++, j++)
        {
            arr.p[i] = r[j];                      // Append the rotating elements in the array.
        }
    }
    return;
}

void max_min()
{
    int i, max, min;
    max = arr.p[0];
    for(i = 1; i < arr.size; i++)
    {
        if(max < arr.p[i])
        {
            max = arr.p[i];
        }
    }

    min = arr.p[0];
    for(i = 1; i < arr.size; i++)
    {
        if(min > arr.p[i])
        {
            min = arr.p[i];
        }
    }
    printf("\nMaximum element = %d\n", max);
    printf("Minimum element = %d\n", min);
    return;
}

void sum_average()
{
    int i, sum = 0;

    for(i = 0; i < arr.size; i++)
    {
        sum += arr.p[i];
    }

    float avg = (float)sum/arr.size;
    printf("\nSum = %d\n", sum);
    printf("Average = %g\n", avg);
    return;
}

void display()
{
    printf("\nThe array :");
    for(int i = 0; i < arr.size; i++)
    {
        printf(" %d", arr.p[i]);
    }
    printf("\n");
    return;
}

void choice_list()
{
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Update\n");
    printf("4. Reverse\n");
    printf("5. Rearrange\n");
    printf("6. Left rotation\n");
    printf("7. Maximum and minimum\n");
    printf("8. Sum and average\n");
    printf("9. Quit\n");
    return;
}

int main(void)
{
    int ch;
    input();
    printf("\nThe array has been initialized.\n\n");

    while(true)
    {
        choice_list();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                Insert();
                display();
                break;

            case 2:
                Delete();
                display();
                break;

            case 3:
                update();
                display();
                break;

            case 4:
                reverse();
                display();
                break;

            case 5:
                rearrange();
                display();
                break;

            case 6:
                left_rotation();
                display();
                break;

            case 7:
                max_min();
                break;

            case 8:
                sum_average();
                break;

            case 9:
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
