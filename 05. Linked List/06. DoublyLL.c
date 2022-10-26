//Java provides built-in class for 'Circular Doubly Linked List' only

#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL, *tail = NULL;

void createList(int arr[], int n)
{
    struct node *t;
    head = (struct node*)malloc(sizeof(struct node));
    if(n == 0) head = NULL;
    else{
        head->prev = NULL;
        head->data = arr[0];
        head->next = NULL;
        tail = head;
    }

    for(int i = 1; i < n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        tail->next = t;
        t->prev = tail;
        t->data = arr[i];
        t->next = NULL;
        tail = t;
    }
    return;
}

int count(struct node *p)
{
    int cnt = 0;
    while(p != NULL){
        cnt++;
        p = p->next;
    }
    return cnt;
}

void insert(int pos, int val)
{
    if(pos < 1 || pos > count(head)+1) return;
    struct node *p = head;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    if(pos == 1){
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else if(pos > 0){
        for(int i = 1; i < pos-1 && p != NULL; i++){
            p = p->next;
        }
        t->prev = p;
        t->next = p->next;
        if(p->next != NULL) p->next->prev = t;
        else tail = t;
        p->next = t;
    }
    return;
}

void delete(int pos)
{
    struct node *p = head;
    struct node *q = NULL;

    if(pos < 1 || pos > count(head)) return;
    else if(pos == 1){
        head = head->next;
        head->prev = NULL;
        printf("Deleted value : %d\n", p->data);
        free(p);
        p = NULL;
    }
    else{
        for(int i = 1; i < pos; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        if(p->next != NULL) p->next->prev = q;
        else tail = q;
        printf("Deleted value : %d\n", p->data);
        free(p);
        p = NULL;
    }
    return;
}

void reverse(struct node *p)
{
    struct node *temp = NULL;
    tail = p;
    while(p != NULL){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        p = p->prev;
        if(p != NULL && p->next == NULL) head = p;
    }
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

void reverseDisplay(struct node *p)
{
    if(p == NULL) return;
    printf(" %d", p->data);
    reverseDisplay(p->prev);
    return;
}

int main(void)
{
    int pos, val;
    int arr[] = {3, 8, 7, 10, 5};
    createList(arr, 5);

    printf("The doubly linked list :");
    display(head);
    printf("The reversed doubly linked list :");
    reverse(head);
    display(head);
    printf("Number of nodes = %d\n", count(head));

    printf("\nEnter the position(1 to 6) and value to insert : ");
    scanf("%d %d", &pos, &val);
    insert(pos, val);
    printf("The doubly linked list :");
    display(head);
    printf("\nEnter the position(1 to 6) to delete : ");
    scanf("%d", &pos);
    delete(pos);
    printf("The doubly linked list :");
    display(head);
    printf("\nDisplaying the list in reverse order : ");
    reverseDisplay(tail);
    printf("\n");
    return 0;
}
