/*
Notes:

1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the relative order of duplicate elements after sorting)
4. Space complexity O(n+r) when r = radix/base of the number system
5. Best and worst case time complexity O(n*d) when d = maximum number of digits
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n = 10;

struct node
{
    int data;
    struct node *next;
} *bin[10];

int find_digits(int arr[])
{
    int i, digit_count = 0, max = arr[0];
    for(i = 1; i < n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    while(max != 0)
    {
        max /= 10;
        ++digit_count;
    }
    return digit_count;
}

void Insert(int data, int indx)
{
    struct node **p = bin;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = data;
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

int Delete(int indx)
{
    struct node *p = bin[indx];
    bin[indx] = bin[indx]->next;
    int data = p->data;
    free(p);
    p = NULL;
    return data;
}

void radix_sort(int arr[])
{
    int i, j, cnt = 0;
    int digits = find_digits(arr);

    while(cnt < digits)
    {
        int div = pow(10, cnt);
        for(i = 0; i < n; i++)
        {
            j = (arr[i]/div)%10;
            Insert(arr[i], j);
        }

        i = j = 0;
        while(j < 10)
        {
            while(bin[j] != NULL)
            {
                arr[i++] = Delete(j);
            }
            ++j;
        }
        cnt++;
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
    int arr[] = {237, 146, 259, 348, 152, 163, 235, 48, 36, 62};
    printf("The array  :");
    display(arr);
    radix_sort(arr);
    printf("Radix sort :");
    display(arr);
    return 0;
}

/*
The array  : 237 146 259 348 152 163 235 48 36 62
Radix sort : 36 48 62 146 152 163 235 237 259 348
*/
