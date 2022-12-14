#include <stdio.h>
#include <stdlib.h>

struct array{
    int *A;
    int size;
    int length;
};

void insert(struct array *ptr, int index, int val)
{
    for(int i = ptr->length; i > index; i--){
        ptr->A[i] = ptr->A[i-1];
    }
    ptr->A[index] = val;
    ptr->length++;
    return;
}

void delete(struct array *ptr, int index)
{
    for(int i = index; i < ptr->length-1; i++){
        ptr->A[i] = ptr->A[i+1];
    }
    ptr->length--;
    return;
}

void display(struct array arr)
{
    printf("\nThe array : ");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    struct array arr;
    printf("Size of the array = ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    int n, pos, val;
    printf("Number of elements = ");
    scanf("%d", &n);
    printf("Enter the element(s) : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;
    }
    display(arr);

    printf("\nEnter a position for inserting an element : ");
    scanf("%d", &pos);
    if(pos > 0 && pos <= arr.length+1){
        printf("Enter an element at position %d : ", pos);
        scanf("%d", &val);
        insert(&arr, pos-1, val); //position = index+1
    }
    else printf("Invalid position\n");
    display(arr);

    printf("\nEnter a position for deleting an element : ");
    scanf("%d", &pos);
    if(pos > 0 && pos <= arr.length){
        delete(&arr, pos-1);
    }
    else printf("Invalid position");
    display(arr);
    return 0;
}

/*
Size of the array = 10
Number of elements = 5
Enter the element(s) : 1 2 3 4 5

The array : 1 2 3 4 5

Enter a position for inserting an element : 1
Enter an element at position 1 : 6

The array : 6 1 2 3 4 5

Enter a position for deleting an element : 3

The array : 6 1 3 4 5
*/
