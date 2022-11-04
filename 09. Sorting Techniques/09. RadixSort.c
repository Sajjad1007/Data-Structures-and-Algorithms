/*
1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the order of duplicate elements after sorting)
4. Extra memory required = radix of the elements
5. Average case time O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int n, *arr;

struct node{
    int data;
    struct node *next;
} **bin = NULL;

int findNumberOfDigits()
{
    int i, digitCount = 0, max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    while(max != 0){
        max /= 10;
        ++digitCount;
    }
    return digitCount;
}

void insert(int data, int indx)
{
    struct node **p = bin;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;

    if(p[indx] == NULL) p[indx] = t;
    else{
        struct node *q = p[indx];
        while(q->next != NULL) q = q->next;
        q->next = t;
    }
    return;
}

int delete(int indx)
{
    struct node *p = bin[indx];
    bin[indx] = bin[indx]->next;
    int data = p->data;
    free(p);
    p = NULL;
    return data;
}

void radixSort()
{
    int i, j, cnt = 0, numberOfDigits;
    numberOfDigits = findNumberOfDigits();
    bin = (struct node**)malloc(10*sizeof(struct node*));
    for(i = 0; i < 10; i++) bin[i] = NULL;

    while(cnt < numberOfDigits){
        int divisor = pow(10, cnt);
        for(i = 0; i < n; i++){
            j = (arr[i] / divisor) % 10;
            insert(arr[i], j);
        }

        i = j = 0;
        while(j < 10){
            while(bin[j] != NULL) arr[i++] = delete(j);
            ++j;
        }
        cnt++;
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

    radixSort();
    printf("\nAfter radix sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}

