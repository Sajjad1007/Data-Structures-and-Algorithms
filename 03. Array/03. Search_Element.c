#include <stdio.h>
#include <stdbool.h>

int n = 5, key, pos;
int arr[] = {1, 2, 4, 5, 6};

int ilinear_search()
{
    for(int i = 0; i < n; i++)
    {
        if(key == arr[i])
        {
            return i;
        }
    }
    return -1;
}

/*
Two time shortening technique for further searching
(a) Transposition
    swap(&arr[i], &arr[i-1]);
(b) Move-to-head
    swap(&arr[i], &arr[0]);
*/

int rlinear_search(int i)
{
    if(key == arr[i])
    {
        return i;
    }
    else if(i == n)
    {
        return -1;
    }
    else
    {
        i = rlinear_search(i+1);
        return i;
    }
}

bool sorted()
{
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

int ibinary_search(int low, int high)
{
    while(low <= high)
    {
        int mid = (low+high)/2;

        if(key == arr[mid])
        {
            return mid;
        }
        else if(key < arr[mid])
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return -1;
}

// Tail recursion and loops are similar.
int rbinary_search(int low, int high)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low+high)/2;

    if(key == arr[mid])
    {
        return mid;
    }
    else if(key < arr[mid])
    {
        return(rbinary_search(low, mid-1));
    }
    else
    {
        return(rbinary_search(mid+1, high));
    }
}

void display()
{
    printf("The array :");
    for(int i = 0; i < n; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n\n");
    return;
}

int main(void)
{
    display();
    printf("Enter an element for searching : ");
    scanf("%d", &key);

    printf("\nLinear search\n");
    pos = ilinear_search()+1;
    printf("\nIterative : ");

    if(pos >= 1)
    {
        printf("%d is at position %d.\n", key, pos);
    }
    else
    {
        printf("%d is not found.\n", key);
    }

    pos = rlinear_search(0)+1;
    printf("Recursive : ");

    if(pos >= 1)
    {
        printf("%d is at position %d.\n", key, pos);
    }
    else
    {
        printf("%d is not found.\n", key);
    }

    if(sorted())
    {
        printf("\nBinary search\n");
        pos = ibinary_search(0, n-1)+1;
        printf("\nIterative : ");

        if(pos >= 1)
        {
            printf("%d is at position %d.\n", key, pos);
        }
        else
        {
            printf("%d is not found.\n", key);
        }

        pos = rbinary_search(0, n-1)+1;
        printf("Recursive : ");

        if(pos >= 1)
        {
            printf("%d is at position %d.\n", key, pos);
        }
        else
        {
            printf("%d is not found.\n", key);
        }
    }
    else
    {
        printf("\nBinary search can not be done in an unsorted array.\n");
    }
    return 0;
}

/*
The array : 2 3 4 5 6

Enter an element for searching : 5

Linear search

Iterative : 5 is at position 4.
Recursive : 5 is at position 4.

Binary search

Iterative : 5 is at position 4.
Recursive : 5 is at position 4.
*/
