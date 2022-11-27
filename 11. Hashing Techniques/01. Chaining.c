/*
Hashing is a searching technique.
For hashing, time complexity is O(1)
Loading Factor, lf = number of elements / size of the hash table
In open hashing, extra spaces will be consumed if needed.
Chaining is a method of open hashing technique.
In chaining method, the size of the hash table should be anything.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

struct node{
    int data;
    struct node *next;
} *hashTable[SIZE]; //hashTable is a pointer to an array of 10 nodes

int hash(int key)
{
    return key % SIZE;
}

void insertSorted(int data)
{
    int indx = hash(data);
    struct node *t, *p = hashTable[indx], *q = NULL;
    t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = NULL;

    if(hashTable[indx] == NULL) hashTable[indx] = t;
    else{
        while(p != NULL && p->data < data){
            q = p;
            p = p->next;
        }

        if(p == hashTable[indx]){
            t->next = hashTable[indx];
            hashTable[indx] = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
    return;
}

bool search(int key)
{
    int indx = hash(key);
    struct node *p = hashTable[indx];

    while(p != NULL){
        if(key == p->data) return true;
        p = p->next;
    }
    return false;
}

void print(struct node *p)
{
    while(p != NULL){
        printf(" %d", p->data);
        p = p->next;
    }
    return;
}

int main(void)
{
    int i, n, data;
    for(i = 0; i < SIZE; i++) hashTable[i] = NULL;

    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &data);
        insertSorted(data);
    }

    printf("\nThe hash table ...\n");
    for(i = 0; i < SIZE; i++){
        printf("\nAt index %d :", i);
        print(hashTable[i]);
    }
    printf("\n");

    printf("\nEnter an element to be searched : ");
    scanf("%d", &data);
    if(search(data)) printf("%d is found\n", data);
    else printf("%d is not found\n", data);
    return 0;
}
