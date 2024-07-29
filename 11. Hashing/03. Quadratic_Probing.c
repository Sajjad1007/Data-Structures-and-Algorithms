/*
Quadratic Probing is a method of closed hashing technique.
*/

#include <stdio.h>
#include <stdbool.h>

#define sz 10

int hash_table[sz];

int hash(int key)
{
    return key%sz;
}

int quadratic_probe(int val)
{
    int i = 0, indx = hash(val);
    while(hash_table[(indx+i*i)%sz] != 0)
    {
        i++;
    }
    return (indx+i*i)%sz;
}

void insert(int val)
{
    int indx = quadratic_probe(val);
    hash_table[indx] = val;
    return;
}

bool search(int key)
{
    int i = 0, indx = hash(key);
    while(i < sz && hash_table[(indx+i*i)%sz] != key)
    {
        if(hash_table[(indx+i*i)%sz] == 0)
        {
            return false;
        }
        else
        {
            i++;
        }
    }
    return (i != sz);
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
        printf("\n%d is found.\n", val);
    }
    else
    {
        printf("\n%d is not found.\n", val);
    }
    return 0;
}

/*
Number of elements : 10
Enter the elements : 4 3 12 9 33 25 7 19 6 20

The hash table

index 0 : 19
index 1 : 20
index 2 : 12
index 3 : 3
index 4 : 4
index 5 : 25
index 6 : 6
index 7 : 33
index 8 : 7
index 9 : 9

Enter an element to be searched : 33

33 is found.
*/
