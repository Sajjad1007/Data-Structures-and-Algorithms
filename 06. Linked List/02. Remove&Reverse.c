#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void createList(int arr[], int n)
{
    struct node *t;
    first = (struct node *)malloc(sizeof(struct node));

    if(n == 0) first = NULL;
    else{
        first->data = arr[0];
        first->next = NULL;
        last = first;
    }

    for(int i = 1; i < n; i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return;
}

bool isSorted(struct node *p)
{
    int val = p->data;
    while(p != NULL){
        if(val > p->data) return false;
        else{
            val = p->data;
            p = p->next;
        }
    }
    return true;
}

void removeDuplicates(struct node *q)
{
    struct node *p = first->next;
    while(p != NULL){
        if(p->data != q->data){
            q = p;
            p = p->next;
        }
        else{
            q->next = p->next;
            free(p);
            p = q->next;
        }
    }
    return;
}

void iterativeReverse(struct node *p)
{
    struct node *q = NULL;
    struct node *r = NULL;

    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }

    first = q;
    return;
}

void recursiveReverse(struct node *p, struct node *q)
{
    if(p != NULL){
        recursiveReverse(p->next, p);
        p->next = q;
    }
    else first = q;
    return;
}

void display(struct node *p)
{
    if(p == NULL){
        printf("\n");
        return;
    }
    printf(" %d", p->data);
    display(p->next);
    return;
}

int main(void)
{
    int arr[] = {3, 5, 6, 8, 8, 8};
    createList(arr, 6);
    printf("The linked list before removal of duplicates :");
    display(first);

    if(isSorted(first)){
        printf("The linked list is sorted\n");
        removeDuplicates(first);
        printf("\nThe linked list after  removal of duplicates :");
        display(first);
        printf("\n");
    }
    else printf("The linked list is not sorted\n");

    iterativeReverse(first);
    printf("After reversing 1st time, linked list (iterative) :");
    display(first);
    recursiveReverse(first, NULL);
    printf("After reversing 2nd time, linked list (recursive) :");
    display(first);
    return 0;
}

/*
The linked list before removal of duplicates : 3 5 6 8 8 8
The linked list is sorted

The linked list after  removal of duplicates : 3 5 6 8

After reversing 1st time, linked list (iterative) : 8 6 5 3
After reversing 2nd time, linked list (recursive) : 3 5 6 8
*/
