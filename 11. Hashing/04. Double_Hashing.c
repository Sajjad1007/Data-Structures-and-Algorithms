/*
Note:

1. Double hashing is a method of closed hashing technique.
2. We can design our own hash function by ensuring that the function always gives the same result.
3. Some of the hash function ideas are mod, mid square, folding etc.
*/

#include <stdio.h>
#include <stdbool.h>

#define sz 10

int hash_table[sz];

int hash1(int key)
{
    return key%sz;
}

int hash2(int key)
{
    return 7-(key%7);              // 7 is the largest among the prime numbers that are less than hash table size.
}

int double_hash(int val)
{
    int i = 0, indx;
    do
    {
        indx = (hash1(val)+i*hash2(val))%sz;
        i++;
    } while(hash_table[indx] != 0);
    return indx;
}

void insert(int val)
{
    int indx = double_hash(val);
    hash_table[indx] = val;
    return;
}

bool search(int key)
{
    int i = 0, indx;
    do
    {
        indx = (hash1(key)+i*hash2(key))%sz;
        if(hash_table[indx] == 0)
        {
            return false;
        }
        else
        {
            i++;
        }
    } while(i < sz && hash_table[indx] != key);

    if(i == sz)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main(void)
{
    int i, n, val;

    printf("Number of elements : ");
    scanf("%d", &n);
    printf("Enter the elements : ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insert(val);
    }

    printf("\nThe hash table\n");
    for(i = 0; i < sz; i++)
    {
        printf("\nindex %d : %d", i, hash_table[i]);
    }

    printf("\n\nEnter an element to be searched : ");
    scanf("%d", &val);
    if(search(val))
    {
        printf("\n%d is found\n", val);
    }
    else
    {
        printf("\n%d is not found\n", val);
    }
    return 0;
}

/*
Number of elements : 10
Enter the elements : 4 3 12 9 33 25 7 19 6 20

The hash table

index 0 : 20
index 1 : 19
index 2 : 12
index 3 : 3
index 4 : 4
index 5 : 33
index 6 : 6
index 7 : 7
index 8 : 25
index 9 : 9

Enter an element to be searched : 33

33 is found
*/
