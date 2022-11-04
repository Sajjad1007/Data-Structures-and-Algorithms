/*
1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Not stable(changes the order of duplicate elements after sorting)
4. Extra memory not required
5. Average case time O(nlogn)
6. Follows the mechanism of insertion sort
*/

#include <stdio.h>
#include <stdlib.h>

int n, *arr;

void shellSort()
{
    int i, j, temp, gap;

    for(gap = n/2; gap >= 1; gap /= 2){
        for(i = gap; i < n; i++){
            temp = arr[i];
            j = i-gap;
            while(j >= 0 && arr[j] > temp){
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = temp;
        }
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

    shellSort();
    printf("\nAfter shell sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
