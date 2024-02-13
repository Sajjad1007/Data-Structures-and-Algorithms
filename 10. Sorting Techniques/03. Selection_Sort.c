/*
Notes:

1. Comparison based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Unstable(changes the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best case time complexity O(n^2)
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

void selection_sort(int arr[])
{
    int i, j, min_indx;
    for(i = 0; i < n-1; i++)
    {
        min_indx = i;
        for(j = i+1; j < n; j++)
        {
            if(arr[min_indx] > arr[j])
            {
                min_indx = j;
            }
        }
        swap(&arr[i], &arr[min_indx]);
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
    selection_sort(arr);
    printf("Selection sort :");
    display(arr);
    return 0;
}

/*
The array      : 11 13 7 12 16 9 24 5 10 3
Selection sort : 3 5 7 9 10 11 12 13 16 24
*/
