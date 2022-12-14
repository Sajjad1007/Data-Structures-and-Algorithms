#include <stdio.h>
#include <stdlib.h>

struct array{
    int A[10];
    int size;
    int length;
};

void reverse(struct array *ptr)
{
    int i, j, temp;
    for(i = 0, j = ptr->length-1; i < j; i++, j--){
        temp = ptr->A[i];
        ptr->A[i] = ptr->A[j];
        ptr->A[j] = temp;
    }
    return;
}

void leftRotation(struct array *ptr, int n)
{
    int i, j = 0;
    int *r = (int*)malloc(n*sizeof(int)); //creating dynamic array for keeping rotating elements

    for(i = 0; i < n; i++){
        r[i] = ptr->A[i]; //keeping rotating elements in the dynamic array
    }
    for(i = 0; i < ptr->length-n; i++){
        ptr->A[i] = ptr->A[i+n]; //shifting the elements towards left
    }
    for(i = ptr->length-n; i < ptr->length; i++, j++){
        ptr->A[i] = r[j]; //appending the rotating elements in the array
    }
    return;
}

void display(struct array arr)
{
    printf("the array : ");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int n;
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};

    printf("Before reversing, ");
    display(arr);
    reverse(&arr);
    printf("After reversing,  ");
    display(arr);

    printf("\nHow many elements you want to rotate? ");
    scanf("%d", &n);
    printf("\nBefore rotation, ");
    display(arr);
    leftRotation(&arr, n);
    printf("After rotation,  ");
    display(arr);
    return 0;
}

/*
interactive console window:

Before reversing, the array : 2 3 4 5 6
After reversing,  the array : 6 5 4 3 2

How many elements you want to rotate? 2

Before rotation, the array : 6 5 4 3 2
After rotation,  the array : 4 3 2 6 5
*/
