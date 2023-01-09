//For binary search in a linked list, time complexity is O(nlogn)

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

void createList(int arr[], int n)
{
    struct node *t;
    head = (struct node *)malloc(sizeof(struct node));

    if(n == 0) head = NULL;
    else{
        head->data = arr[0];
        head->next = NULL;
        tail = head;
    }

    for(int i = 1; i < n; i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        tail->next = t;
        tail = t;
    }
    return;
}

void printMiddleOf(struct node *p)
{
    struct node *q = p;
    while(q){
        q = q->next;
        if(q) q = q->next;
        if(q) p = p->next;
    }
    printf("The middle node : %d\n", p->data);
    return;
}

void display(struct node *p)
{
    while(p){
        printf(" %d", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    int pos, val;
    int arr[] = {8, 6, 3, 9, 10, 4, 2, 12, 7, 1};
    createList(arr, 10);

    printf("The linked list :");
    display(head);
    printMiddleOf(head); //this will print (ceiling of (n / 2))th element of the linked list
    return 0;
}

/*
The linked list : 8 6 3 9 10 4 2 12 7 1
The middle node : 10
*/
