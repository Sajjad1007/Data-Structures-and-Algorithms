/*
Notes:

1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Unstable(changes the relative order of duplicate elements after sorting)
4. Space complexity O(m) when m = maximum element in the list
5. Best and worst case time complexity O(n)
*/

#include <stdio.h>

int n = 10;

int find_max(int arr[])
{
    int i, max = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[])
{
    int i, j;
    int max = find_max(arr);
    int cnt[max+1];

    for(i = 0; i <= max; i++)
    {
        cnt[i] = 0;
    }
    for(i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }

    i = j = 0;
    while(j <= max)
    {
        if(cnt[j] > 0)
        {
            arr[i++] = j;
            cnt[j]--;
        }
        else
        {
            j++;
        }
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
    printf("The array  :");
    display(arr);
    count_sort(arr);
    printf("Count sort :");
    display(arr);
    return 0;
}

/*
The array  : 11 13 7 12 16 9 24 5 10 3
Count sort : 3 5 7 9 10 11 12 13 16 24
*/
