/*
1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Not stable(changes the relative order of duplicate elements after sorting)
4. Extra memory not required
5. Maximum number of comparisons = n^2
6. Maximum number of swaps = n^2
7. Worst case time O(n^2)
8. Average and best case time O(nlogn)
*/

#include <stdio.h>
#include <stdlib.h>

int n, *arr;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;
    do{
        while(arr[i] <= pivot && i < n) ++i;
        while(arr[j] > pivot) --j;

        if(i < j) swap(&arr[i], &arr[j]);
    } while(i < j);

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int low, int high)
{
    int j;
    if(low < high){
        j = partition(low, high);
        quickSort(low, j-1);
        quickSort(j+1, high);
    }
    return;
}

int main(void)
{
    int i;
    printf("Number of elements = ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    quickSort(0, n-1);
    printf("\nAfter quick sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
