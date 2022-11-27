/*
Quadratic Probing is a method of closed hashing technique.
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int hashTable[SIZE] = {0};

int hash(int key)
{
    return key % SIZE;
}

int probe(int data)
{
    int i = 0, indx = hash(data);
    while(hashTable[(indx+i*i) % SIZE] != 0) i++;
    return (indx+i*i) % SIZE;
}

void insert(int data)
{
    int indx = probe(data);
    hashTable[indx] = data;
    return;
}

bool search(int key)
{
    int i = 0, indx = hash(key);
    while(hashTable[(indx+i*i) % SIZE] != key){
        if(hashTable[(indx+i*i) % SIZE] == 0) return false;
        else i++;
    }
    return true;
}

int main(void)
{
    int i, n, data;

    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter %d elements : ", n);
    for(i = 0; i < n; i++){
        scanf("%d", &data);
        insert(data);
    }

    printf("\nThe hash table :");
    for(i = 0; i < SIZE; i++) printf(" %d", hashTable[i]);
    printf("\n");

    printf("\nEnter an element to be searched : ");
    scanf("%d", &data);
    if(search(data)) printf("%d is found\n", data);
    else printf("%d is not found\n", data);
    return 0;
}
