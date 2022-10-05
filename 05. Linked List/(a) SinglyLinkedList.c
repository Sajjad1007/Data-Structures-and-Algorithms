/*
Here recursive version of each functions are demonstrated
Space complexity of traversing a linked list with recursion in O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
} *first = NULL, *last = NULL;

void createList(int arr[], int n)
{
    struct node *t;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for(int i = 1; i < n; i++){
        t = (struct node*)malloc(sizeof(struct node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return;
}

int count(struct node *p)
{
    int cnt = 0;
    if(p == 0){
        return cnt;
    }
    else{
        cnt = count(p->next);
        return cnt + 1;
    }
}

int sumOfElements(struct node *p)
{
    int data = 0;
    if(p == 0){
        return data;
    }
    else{
        data = p->data;
        return data + sumOfElements(p->next);
    }
}

int getMax(struct node *p)
{
    if(p->next == NULL){
        return p->data;
    }
    else{
        int x = getMax(p->next);
        return x > p->data ? x : p->data;
    }
}

//we can improve this linear search by using 'Transposition' or 'Move-to-head' technique just like arrays
int linearSearch(struct node *p, int key)
{
    static int pos = 1;
    if(p == NULL){
        return 0;
    }
    else if(key == p->data){
        return pos;
    }
    else{
        pos++;
        linearSearch(p->next, key);
    }
}

void insert(int pos, int val)
{
    if(pos < 1 || pos > count(first)+1) return;
    struct node *p = first;
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = val;
    if(pos == 1){
        t->next = first;
        first = t;
    }
    else if(pos > 0){
        for(int i = 1; i < pos-1 && p != NULL; i++){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    return;
}

void delete(int pos)
{
    struct node *p = first;
    struct node *q = NULL;

    if(pos < 1 || pos > count(first)) return;
    else if(pos == 1){
        p = first;
        first = first->next;
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
    }
}

void display(struct node *p)
{
    if(p == NULL){
        return;
    }
    printf(" %d", p->data);
    display(p->next);
    return;
}

void reverseDisplay(struct node *p)
{
    if(p == NULL){
        return;
    }
    reverseDisplay(p->next);
    printf(" %d", p->data);
    return;
}

int main(void)
{
    int key, arr[] = {3, 8, 7, 10, 5};
    int pos, val;
    createList(arr, 5);
    printf("The linked list :");
    display(first);
    printf("\nThe reverse linked list :");
    reverseDisplay(first);

    printf("\n\nNumber of nodes = %d\n", count(first));
    printf("Sum of the elements = %d\n", sumOfElements(first));
    printf("Maximum element = %d\n", getMax(first));

    printf("\nEnter an element to be searched : ");
    scanf("%d", &key);
    pos = linearSearch(first, key);
    if(pos != 0){
        printf("%d is found in position %d of the linked list\n", key, pos);
    }
    else{
        printf("%d is not found in the linked list\n", key);
    }

    printf("\nEnter the position(1 to 6) and value to insert : ");
    scanf("%d %d", &pos, &val);
    insert(pos, val);
    printf("The linked list :");
    display(first);
    printf("\n\nEnter the position(1 to 6) to delete : ");
    scanf("%d", &pos);
    delete(pos);
    printf("The linked list :");
    display(first);
    printf("\n");
    return 0;
}
