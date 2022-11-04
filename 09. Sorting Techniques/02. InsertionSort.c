/*
1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Extra memory not required
5. Maximum number of comparisons = n^2
6. Maximum number of swaps = n^2
7. Worst case time O(n^2)
8. Best case time O(n)
9. Better for sorting linked lists
*/

#include <stdio.h>
#include <stdlib.h>

int n, *arr;

void insertionSort()
{
    int i, j, temp;

    for(i = 1; i < n; i++){
        temp = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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

    insertionSort();
    printf("\nAfter insertion sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
