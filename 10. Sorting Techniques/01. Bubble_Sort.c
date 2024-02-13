/*
Notes:

1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best case time complexity O(n)
6. Worst case time complexity O(n^2)
*/

#include <stdio.h>
#include <stdbool.h>

int n = 10;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubble_sort(int arr[])
{
    int i, j;
    bool swapped;

    for(i = 0; i < n-1; i++)
    {
        swapped = false;
        for(j = 0; j < n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }
        if(swapped = false)        // The array is already in sorted order.
        {
            break;
        }
    }
    return;
}

void display(int t[])
{
    for(int i = 0; i < n; i++)
    {
        printf(" %d", t[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    printf("The array   :");
    display(arr);
    bubble_sort(arr);
    printf("Bubble sort :");
    display(arr);
    return 0;
}

/*
The array   : 11 13 7 12 16 9 24 5 10 3
Bubble sort : 3 5 7 9 10 11 12 13 16 24
*/
