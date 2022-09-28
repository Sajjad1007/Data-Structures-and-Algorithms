#include <stdio.h>
#include <stdlib.h>

struct Array{
    int *A;
    int size;
    int length;
};

void reverse(struct Array *ptr)
{
    int i, j, temp;
    for(i = 0, j = ptr->length-1; i < j; i++, j--){
        temp = ptr->A[i];
        ptr->A[i] = ptr->A[j];
        ptr->A[j] = temp;
    }
    return;
}

void leftRotation(struct Array *ptr, int n)
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

void display(struct Array arr)
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
    struct Array arr;
    printf("Size of the array = ");
    scanf("%d", &arr.size);

    arr.A = (int*)malloc(arr.size*sizeof(int));
    arr.length = 0;

    int n;
    printf("Number of elements = ");
    scanf("%d", &n);
    printf("Enter the element(s) : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;
    }

    printf("\nBefore reversing, ");
    display(arr);
    reverse(&arr);
    printf("After reversing, ");
    display(arr);

    printf("\nHow many elements you want to rotate? ");
    scanf("%d", &n);
    printf("\nBefore rotation, ");
    display(arr);
    leftRotation(&arr, n);
    printf("After rotation, ");
    display(arr);
    return 0;
}
