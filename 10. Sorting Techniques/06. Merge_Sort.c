/*
Notes:

1. Comparison based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Space complexity O(n)
5. Best and worst case time complexity O(nlogn)
6. Done in post-order traversals in case of recursive procedure
*/

#include<stdio.h>

int n = 10;

void merge(int t[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int aux[n];

    while(i <= mid && j <= high){
        if(t[i] <= t[j]){
            aux[k++] = t[i++];
        }
        else{
            aux[k++] = t[j++];
        }
    }

    while(i <= mid){
        aux[k++] = t[i++];
    }
    while(j <= high){
        aux[k++] = t[j++];
    }
    for(i = low; i <= high; i++){
        t[i] = aux[i];
    }
    return;
}

void iterative_merge_sort(int p[])
{
    int i, k, low, high, mid;
    for(k = 2; k <= n; k *= 2){
        for(i = 0; i + k - 1 < n; i += k){
            low = i;
            high = i + k - 1;
            mid = (low + high) / 2;
            merge(p, low, mid, high);
        }

        if(n - i > k / 2){
            low = i;
            high = i + k - 1;
            mid = (low + high) / 2;
            merge(p, low, mid, n - 1);
        }
    }
    if(k / 2 < n){
        merge(p, 0, k / 2 - 1, n - 1);
    }
    return;
}

//Space consumed by this recursive function in the stack = log(n).
void recursive_merge_sort(int q[], int low, int high)
{
    if(low < high){
        int mid = (low + high) / 2;
        recursive_merge_sort(q, low, mid);
        recursive_merge_sort(q, mid + 1, high);
        merge(q, low, mid, high);
    }
    return;
}

void display(int t[])
{
    for(int i = 0; i < n; i++){
        printf(" %d", t[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int i, arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    int p[n], q[n];

    for(i = 0; i < n; i++){
        p[i] = q[i] = arr[i];
    }
    printf("The array  :");
    display(arr);

    iterative_merge_sort(p);
    printf("\nMerge sort (iterative) :");
    display(p);
    recursive_merge_sort(q, 0, n - 1);
    printf("Merge sort (recursive) :");
    display(q);
    return 0;
}

/*
The array  : 11 13 7 12 16 9 24 5 10 3

Merge sort (iterative) : 3 5 7 9 10 11 12 13 16 24
Merge sort (recursive) : 3 5 7 9 10 11 12 13 16 24
*/
