/*
Notes:

1. Comparison based sorting technique
2. Adaptive(takes less amount of time over already sorted list)
3. Unstable(changes the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best case time O(nlogn)
6. Worst case time O(n^2)
6. Similar to the mechanism of insertion sort
*/

#include <stdio.h>

int n = 10;

void shell_sort(int arr[])
{
    int i, j, temp, gap;
    for(gap = n / 2; gap >= 1; gap /= 2){
        for(i = gap; i < n; i++){
            temp = arr[i];
            j = i - gap;
            while(j >= 0 && arr[j] > temp){
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
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
    int arr[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    printf("The array  :");
    display(arr);
    shell_sort(arr);
    printf("Shell sort :");
    display(arr);
    return 0;
}

/*
The array  : 11 13 7 12 16 9 24 5 10 3
Shell sort : 3 5 7 9 10 11 12 13 16 24
*/
