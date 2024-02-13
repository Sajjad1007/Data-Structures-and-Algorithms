/*
Notes:

1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Unstable(changes the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best case time complexity O(nlogn)
6. Worst case time complexity O(n^2)
*/

#include <stdio.h>

int n = 10;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    do
    {
        while(arr[i] <= pivot && i < high)
        {
            ++i;
        }
        while(arr[j] > pivot && j > low)
        {
            --j;
        }
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while(i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quick_sort(int arr[], int low, int high)
{
    if(low < high)
    {
        int j = partition(arr, low, high);        // arr[low] has been placed at its sorted index j.
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);
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
    printf("The array  :");
    display(arr);
    quick_sort(arr, 0, n-1);
    printf("Quick sort :");
    display(arr);
    return 0;
}

/*
The array  : 11 13 7 12 16 9 24 5 10 3
Quick sort : 3 5 7 9 10 11 12 13 16 24
*/
