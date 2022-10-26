#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

struct node *createList(int arr[], int n)
{
    struct node *t;
    first = (struct node*)malloc(sizeof(struct node));
    if(n == 0) first = NULL;
    else{
        first->data = arr[0];
        first->next = NULL;
        last = first;
    }

    for(int i = 1; i < n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return first;
}

void concatenate(struct node *p, struct node *q)
{
    while(p->next != NULL) p = p->next;
    p->next = q;
    return;
}

struct node *merge(struct node *p, struct node *q)
{
    struct node *r = NULL;

    if(p->data < q->data){
        r = last = p; //last will point to the last node of the merged linked list
        p = p->next;
        last->next = NULL;
    }
    else{
        r = last = q;
        q = q->next;
        last->next = NULL;
    }

    while(p != NULL && q != NULL){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }

    if(p != NULL) last->next = p;
    else last->next = q;
    return r;
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
    int arr1[] = {1, 2, 4, 5, 7};
    struct node *p = createList(arr1, 5);
    int arr2[] = {3, 6, 8, 9, 10};
    struct node *q = createList(arr2, 5);

    printf("1st linked list :");
    display(p);
    printf("\n2nd linked list :");
    display(q);

    concatenate(p, q);
    printf("\nAfter concatenation, the linked list :");
    display(p);

    p = createList(arr1, 5);
    q = createList(arr2, 5);
    printf("\nAfter merging, the linked list :");
    display(merge(p, q));
    return 0;
}
