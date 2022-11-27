/*
Double hashing is a method of closed hashing technique.
We can design our own hash function by making sure that the function always gives the same result.
Some of the hash function ideas are mod, mid square, folding etc.
*/

#include <stdio.h>
#include <stdbool.h>

#define SIZE 10

int hashTable[SIZE] = {0};

int hash1(int key)
{
    return key % SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7); //7 is the largest among the prime numbers that are less than hash table size
}

int probe(int data)
{
    int i = 0, indx;
    do{
        indx = (hash1(data) + i*hash2(data)) % SIZE;
        i++;
    } while(hashTable[indx] != 0);
    return indx;
}

void insert(int data)
{
    int indx = probe(data);
    hashTable[indx] = data;
    return;
}

bool search(int key)
{
    int i = 0, indx;
    do{
        indx = (hash1(key) + i*hash2(key)) % SIZE;
        if(hashTable[indx] == 0) return false;
        else i++;
    } while(hashTable[indx] != key);
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
