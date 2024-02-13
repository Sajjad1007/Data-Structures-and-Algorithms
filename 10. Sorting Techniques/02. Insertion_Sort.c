/*
Notes:

1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best case time complexity O(n)
6. Worst case time complexity O(n^2)
7. Better for sorting linked lists
*/

#include <stdio.h>

int n = 10;

void insertion_sort(int arr[])
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    printf("The array      :");
    display(arr);
    insertion_sort(arr);
    printf("Insertion sort :");
    display(arr);
    return 0;
}

/*
The array      : 11 13 7 12 16 9 24 5 10 3
Insertion sort : 3 5 7 9 10 11 12 13 16 24
*/
