/*
1. Comparison based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Not stable(changes the relative order of duplicate elements after sorting)
4. Extra memory not required
5. Maximum number of comparisons = n^2
6. Maximum number of swaps = n
7. Worst case time O(n^2)
8. Best case time O(n)
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

void selectionSort()
{
    int i, j, minIndex;
    for(i = 0; i < n-1; i++){
        minIndex = i;
        for(j = i+1; j < n; j++){
            if(arr[minIndex] > arr[j]) minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);
    }
    return;
}

int main(void)
{
    int i;
    printf("Number of elements = ");
    scanf("%d", &n);
    arr = (int*)malloc((n+1)*sizeof(int));

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++) scanf("%d", &arr[i]);

    selectionSort();
    printf("\nAfter selection sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
