#include <stdio.h>
#include <stdbool.h>

struct array{
    int A[10];
    int size;
    int length;
};

bool isSorted(struct array arr)
{
    for(int i = 0; i < arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return false;
        }
    }
    return true;
}

void insertSorted(struct array *ptr, int val)
{
    int i = ptr->length-1;
    while(i >= 0 && val < ptr->A[i]){
        ptr->A[i+1] = ptr->A[i];
        i--;
    }
    ptr->A[i+1] = val;
    ptr->length++;
    return;
}

void rearrange(struct array *ptr)
{
    int i = 0;
    int j = ptr->length-1;
    while(i < j){
        while(ptr->A[i] < 0) i++;
        while(ptr->A[j] > 0) j--;

        if(i < j){
            int temp = ptr->A[i];
            ptr->A[i] = ptr->A[j];
            ptr->A[j] = temp;
        }
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
    struct array arr = {{2, 3, 6, 10, 15, 19, 22, 24, 27}, 10, 9};
    struct array ara = {{2, -13, 25, 10, -4, 7, -5, -18}, 10, 8};
    int val;
    printf("Before insertion, ");
    display(arr);

    if(arr.length == arr.size){
        printf("The array is full.\n");
    }
    else if(isSorted(arr)){
        printf("The array is sorted.");
        printf("\n\nEnter an element to be inserted : ");
        scanf("%d", &val);
        insertSorted(&arr, val);
        printf("After insertion, ");
        display(arr);
    }
    else{
        printf("The array is not sorted.\n");
    }

    printf("\nBefore rearranging, ");
    display(ara);
    rearrange(&ara);
    printf("After rearranging, ");
    display(ara);
    return 0;
}
