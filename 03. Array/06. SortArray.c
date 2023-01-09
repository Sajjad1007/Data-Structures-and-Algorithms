#include <stdio.h>
#include <stdbool.h>

struct array{
    int A[10];
    int size;
    int length;
};

bool isSorted(struct array arr)
{
    for(int i = 0; i < arr.length - 1; i++){
        if(arr.A[i] > arr.A[i + 1]) return false;
    }
    return true;
}

void insertSorted(struct array *ptr, int val)
{
    int i = ptr->length - 1;
    while(i >= 0 && val < ptr->A[i]){
        ptr->A[i + 1] = ptr->A[i];
        i--;
    }
    ptr->A[i + 1] = val;
    ptr->length++;
    return;
}

//This functions rearranges all the negatives to the left and all the positives to the right
void rearrange(struct array *ptr)
{
    int i = 0;
    int j = ptr->length - 1;

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

void display(struct array arr, int n)
{
    printf("array %d :", n);
    for(int i = 0; i < arr.length; i++){
        printf(" %d", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int val;
    struct array arr1 = {{2, 3, 6, 10, 15, 19, 22, 24, 27}, 10, 9};
    struct array arr2 = {{2, -13, 25, 10, -4, 7, -5, -18}, 10, 8};
    printf("Before insertion, ");
    display(arr1, 1);

    if(arr1.length == arr1.size){
        printf("The array is full\n");
    }
    else if(isSorted(arr1)){
        printf("This array is sorted");
        printf("\n\nEnter an element to be inserted : ");
        scanf("%d", &val);
        insertSorted(&arr1, val);
        printf("\nAfter insertion, ");
        display(arr1, 1);
    }
    else printf("The array is not sorted\n");

    printf("\nBefore rearranging, ");
    display(arr2, 2);
    rearrange(&arr2);
    printf("After  rearranging, ");
    display(arr2, 2);
    return 0;
}

/*
Before insertion, array 1 : 2 3 6 10 15 19 22 24 27
This array is sorted

Enter an element to be inserted : 9

After insertion, array 1 : 2 3 6 9 10 15 19 22 24 27

Before rearranging, array 2 : 2 -13 25 10 -4 7 -5 -18
After  rearranging, array 2 : -18 -13 -5 -4 10 7 25 2
*/
