/*
1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Extra memory not required
5. Maximum number of comparisons = n^2
6. Maximum number of swaps = n^2
7. Worst case time O(n^2)
8. Best case time O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n, *arr;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void bubbleSort()
{
    int i, j;
    bool isSwappped;

    for(i = 0; i < n-1; i++){
        isSwappped = false;
        for(j = 0; j < n-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                isSwappped = true;
            }
        }
        if(isSwappped = false) break; //array is already in sorted order
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

    bubbleSort();
    printf("\nAfter bubble sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
