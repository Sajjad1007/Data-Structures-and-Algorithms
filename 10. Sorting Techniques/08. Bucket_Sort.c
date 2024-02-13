/*
Notes:

1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Space complexity O(n+m) when m = maximum element in the list
5. Best case time complexity O(n)
6. Worst case time complexity O(n^2)
*/

#include <stdio.h>
#include <stdlib.h>

int n = 10;

struct node
{
    int data;
    struct node *next;
};

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

void Insert(struct node *bin[], int indx)
{
    struct node **p = bin;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = indx;
    t->next = NULL;

    if(p[indx] == NULL)
    {
        p[indx] = t;
    }
    else
    {
        struct node *q = p[indx];
        while(q->next != NULL)
        {
            q = q->next;
        }
        q->next = t;
    }
    return;
}

int Delete(struct node *bin[], int indx)
{
    struct node *p = bin[indx];
    bin[indx] = bin[indx]->next;
    int data = p->data;
    free(p);
    p = NULL;
    return data;
}

void bin_sort(int arr[])
{
    int i, j;
    int max = find_max(arr);
    struct node *bin[max+1];

    for(i = 0; i <= max; i++)
    {
        bin[i] = NULL;
    }
    for(i = 0; i < n; i++)
    {
        Insert(bin, arr[i]);
    }

    i = j = 0;
    while(j <= max)
    {
        while(bin[j] != NULL)
        {
            arr[i++] = Delete(bin, j);
        }
        ++j;
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
    int arr[] = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};
    printf("The array :");
    display(arr);
    bin_sort(arr);
    printf("Bin sort  :");
    display(arr);
    return 0;
}

/*
The array : 6 8 3 10 15 6 9 12 6 3
Bin sort  : 3 3 6 6 6 8 9 10 12 15
*/
