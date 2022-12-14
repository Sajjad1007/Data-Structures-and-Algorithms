/*
1. Comparison based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Extra memory required = n + logn
5. Maximum number of comparisons = nlogn
6. Maximum number of swaps = nlogn
7. Average case time O(nlogn)
8. Done in post-order traversals in case of recursive procedure
*/

#include<stdio.h>
#include<stdlib.h>

int n, *arr1, *arr2, *aux;

void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid+1, k = low;
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]) aux[k++] = arr[i++];
        else aux[k++] = arr[j++];
    }

    while(i <= mid) aux[k++] = arr[i++];
    while(j <= high) aux[k++] = arr[j++];

    for(i = low; i <= high; i++) arr[i] = aux[i];
    return;
}

void iMergeSort()
{
    int i, p, low, high, mid;
    for(p = 2; p <= n; p *= 2){
        for(i = 0; i+p-1 < n; i += p){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merge(arr1, low, mid, high);
        }

        if(n-i > p/2){
            low = i;
            high = i+p-1;
            mid = (low+high)/2;
            merge(arr1, low, mid, n-1);
        }
    }
    if(p/2 < n) merge(arr1, 0, p/2-1, n-1);
    return;
}

//Space consumed by this recursive function in the stack = logn
void rMergeSort(int low, int high)
{
    int mid;
    if(low < high){
        mid = (low+high)/2;
        rMergeSort(low, mid);
        rMergeSort(mid+1, high);
        merge(arr2, low, mid, high);
    }
    return;
}

int main(void)
{
    int i;
    printf("Number of elements = ");
    scanf("%d", &n);
    arr1 = (int*)malloc(n*sizeof(int));
    arr2 = (int*)malloc(n*sizeof(int));
    aux = (int*)malloc(n*sizeof(int));

    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr1[i]);
        arr2[i] = arr1[i];
    }

    iMergeSort();
    printf("\nAfter merge sort (iterative) :");
    for(i = 0; i < n; i++) printf(" %d", arr1[i]);

    rMergeSort(0, n-1);
    printf("\nAfter merge sort (recursive) :");
    for(i = 0; i < n; i++) printf(" %d", arr2[i]);
    printf("\n");
    return 0;
}
