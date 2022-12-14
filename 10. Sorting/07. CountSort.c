/*
1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the order of duplicate elements after sorting)
4. Extra memory required = maximum element in the list + 1
5. Average case time O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int n, *arr, *cnt;

int findMax()
{
    int i, max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void countSort()
{
    int i, j, max;
    max = findMax();
    cnt = (int*)malloc((max+1)*sizeof(int));

    for(i = 0; i <= max; i++) cnt[i] = 0;
    for(i = 0; i < n; i++) cnt[arr[i]]++;

    i = j = 0;
    while(j <= max){
        if(cnt[j] > 0){
            arr[i++] = j;
            cnt[j]--;
        }
        else j++;
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

    countSort();
    printf("\nAfter count sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
