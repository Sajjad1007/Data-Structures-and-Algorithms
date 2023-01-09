#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
        head->next = head;
        tail = head;
    }

    for(int i = 1; i < n; i++){
        t = (struct node *)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = head;
        tail->next = t;
        tail = t;
    }
    return;
}

int count(struct node *p)
{
    int cnt = 0;
    if(p == NULL) return cnt;
    else{
        do{
            cnt++;
            p = p->next;
        } while(p != head);
        return cnt;
    }
}

void insert(int pos, int val)
{
    if(pos < 1 || pos > count(head) + 1) return;
    struct node *p = head;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = val;

    if(pos == 1){
        t->next = head;
        head = t;
        tail->next = head;
    }
    else if(pos > 0){
        for(int i = 1; i < pos - 1 && p != NULL; i++) p = p->next;
        t->next = p->next;
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
        tail->next = head;
        printf("Deleted value : %d\n", p->data);
        free(p);
    }
    else{
        for(int i = 1; i < pos; i++){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        printf("Deleted value : %d\n", p->data);
        free(p);
        p = NULL;
    }
    return;
}

void display(struct node *p)
{
    do{
        printf(" %d", p->data);
        p = p->next;
    } while(p != head);

    printf("\n");
    return;
}

void rdisplay(struct node *p)
{
    static bool flag = false;

    if(p != head || flag == false){
        flag = true;
        printf(" %d", p->data);
        display(p->next);
    }
    else printf("\n");

    flag = false;
    return;
}

int main(void)
{
    int pos, val;
    int arr[] = {3, 8, 7, 2, 5};
    createList(arr, 5);

    printf("The circular linked list (using loop) :");
    display(head);
    printf("The circular linked list (using recursion) :");
    rdisplay(head);
    printf("Number of nodes = %d\n", count(head));

    printf("\nEnter the position (1 to 6) and value to insert : ");
    scanf("%d %d", &pos, &val);
    insert(pos, val);
    printf("The circular linked list :");
    display(head);
    printf("\nEnter the position (1 to 6) to delete : ");
    scanf("%d", &pos);
    delete(pos);
    printf("The circular linked list :");
    display(head);
    return 0;
}

/*
The circular linked list (using loop) : 3 8 7 2 5
The circular linked list (using recursion) : 3 8 7 2 5
Number of nodes = 5

Enter the position (1 to 6) and value to insert : 5 6
The circular linked list : 3 8 7 2 6 5

Enter the position (1 to 6) to delete : 3
Deleted value : 7
The circular linked list : 3 8 2 6 5
*/
