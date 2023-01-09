/*
Here recursive version of each functions are demonstrated
Space complexity of traversing a linked list with recursion is O(n)
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

int count(struct node *p)
{
    int cnt = 0;
    if(p == 0) return cnt;
    else{
        cnt = count(p->next);
        return cnt + 1;
    }
}

int sumOfElements(struct node *p)
{
    int data = 0;
    if(p == 0) return data;
    else{
        data = p->data;
        return data + sumOfElements(p->next);
    }
}

int getMax(struct node *p)
{
    if(p == NULL) return 0;
    else if(p->next == NULL) return p->data;
    else{
        int x = getMax(p->next);
        return x > p->data ? x : p->data;
    }
}

//We can improve this linear search by using 'Transposition' or 'Move-to-head' technique just like arrays
int linearSearch(struct node *p, int key)
{
    static int pos = 1;
    if(p == NULL) return 0;
    else if(key == p->data) return pos;
    else{
        pos++;
        return linearSearch(p->next, key);
    }
}

void insert(int pos, int val)
{
    if(pos < 1 || pos > count(first) + 1) return;
    struct node *p = first;
    struct node *t = (struct node *)malloc(sizeof(struct node));
    t->data = val;

    if(pos == 1){
        t->next = first;
        first = t;
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
    struct node *p = first;
    struct node *q = NULL;

    if(pos < 1 || pos > count(first)) return;
    else if(pos == 1){
        p = first;
        first = first->next;
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
        printf("Deleted value : %d\n", p->data);
        free(p);
        p = NULL;
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
    reverseDisplay(p->next);
    printf(" %d", p->data);
    return;
}

int main(void)
{
    int pos, val, key;
    int arr[] = {3, 8, 7, 2, 5};

    createList(arr, 5);
    printf("The linked list :");
    display(first);
    printf("The reversed linked list :");
    reverseDisplay(first);

    printf("\n\nNumber of nodes = %d\n", count(first));
    printf("Sum of the elements = %d\n", sumOfElements(first));
    printf("Maximum element = %d\n", getMax(first));

    printf("\nEnter an element to be searched : ");
    scanf("%d", &key);
    pos = linearSearch(first, key);

    if(pos != 0) printf("%d is found at position %d\n", key, pos);
    else printf("%d is not found\n", key);

    printf("\nEnter the position (1 to %d) and value to insert : ", count(first) + 1);
    scanf("%d %d", &pos, &val);
    insert(pos, val);
    printf("The linked list :");
    display(first);

    if(count(first) > 0){
        printf("\nEnter the position (1 to 6) to delete : ");
        scanf("%d", &pos);
        delete(pos);
        printf("The linked list :");
        display(first);
    }
    return 0;
}

/*
The linked list : 3 8 7 2 5
The reversed linked list : 5 2 7 8 3

Number of nodes = 5
Sum of the elements = 25
Maximum element = 8

Enter an element to be searched : 2
2 is found at position 4

Enter the position (1 to 6) and value to insert : 5 6
The linked list : 3 8 7 2 6 5

Enter the position (1 to 6) to delete : 3
Deleted value : 7
The linked list : 3 8 2 6 5
*/
