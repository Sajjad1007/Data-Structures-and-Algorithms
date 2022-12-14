/*
In closed hashing, extra spaces will not be consumed.
Linear Probing is a method of closed hashing technique.
In linear probing/quadratic probing/double hashing method, the hash table size should be at least
double of the number of elements.
It is preferred to use a prime number as the size of the hash function to reduce collision.
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10 //as the number of elements to be inserted unknown, by default size of the hash table is 10

int hashTable[SIZE] = {0};

int hash(int key)
{
    return key % SIZE;
}

int probe(int data)
{
    int i = 0, indx = hash(data);
    while(hashTable[(indx+i) % SIZE] != 0) i++;
    return (indx+i) % SIZE;
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
    while(hashTable[(indx+i) % SIZE] != key){
        if(hashTable[(indx+i) % SIZE] == 0) return false;
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
