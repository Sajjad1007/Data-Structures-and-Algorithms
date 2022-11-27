/*
1. Index based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Stable(preserves the order of duplicate elements after sorting)
4. Extra memory required = maximum element in the list + 1
5. Average case time O(n)
*/

#include <stdio.h>
#include <stdlib.h>

int n, *arr;

struct node{
    int data;
    struct node *next;
} **bin = NULL;

int findMax()
{
    int i, max = arr[0];
    for(i = 1; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

void insert(int indx)
{
    struct node **p = bin;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = indx;
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

void binSort()
{
    int i, j, max;
    max = findMax();
    bin = (struct node**)malloc((max+1)*sizeof(struct node*));

    for(i = 0; i <= max; i++) bin[i] = NULL;
    for(i = 0; i < n; i++) insert(arr[i]);

    i = j = 0;
    while(j <= max){
        while(bin[j] != NULL) arr[i++] = delete(j);
        ++j;
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

    binSort();
    printf("\nAfter bin sort :");
    for(i = 0; i < n; i++) printf(" %d", arr[i]);
    printf("\n");
    return 0;
}
