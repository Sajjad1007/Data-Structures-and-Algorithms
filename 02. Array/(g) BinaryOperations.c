//Some other binary operations of arrays are append(), concat(), compare(), copy() etc.

#include <stdio.h>

struct array{
    int A[20];
    int length;
};

struct array merge(struct array arr1, struct array arr2)
{
    int i = 0, j = 0, k = 0;
    struct array arr3;

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        }
        else{
            arr3.A[k++] = arr2.A[j++];
        }
    }

    while(i < arr1.length){
        arr3.A[k++] = arr1.A[i++];
    }
    while(j < arr2.length){
        arr3.A[k++] = arr2.A[j++];
    }

    arr3.length = k;
    return arr3;
}

//getUnion(), getIntersection() and getDifference() functions will work when the arrays are sorted
struct array getUnion(struct array arr1, struct array arr2)
{
    int i = 0, j = 0, k = 0;
    struct array arr3;

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        }
        else if(arr2.A[j] < arr1.A[i]){
            arr3.A[k++] = arr2.A[j++];
        }
        else{
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
    }

    while(i < arr1.length){
        arr3.A[k++] = arr1.A[i++];
    }
    while(j < arr2.length){
        arr3.A[k++] = arr2.A[j++];
    }

    arr3.length = k;
    return arr3;
}

struct array getIntersection(struct array arr1, struct array arr2)
{
    int i = 0, j = 0, k = 0;
    struct array arr3;

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] == arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
            j++;
        }
        else if(arr1.A[i] < arr2.A[j]){
            i++;
        }
        else{
            j++;
        }
    }

    arr3.length = k;
    return arr3;
}

struct array getDifference(struct array arr1, struct array arr2)
{
    int i = 0, j = 0, k = 0;
    struct array arr3;

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] < arr2.A[j]){
            arr3.A[k++] = arr1.A[i++];
        }
        else if(arr1.A[i] > arr2.A[j]){
            j++;
        }
        else{
            i++;
            j++;
        }
    }

    while(i < arr1.length){
        arr3.A[k++] = arr1.A[i++];
    }

    arr3.length = k;
    return arr3;
}

void display(struct array arr)
{
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    struct array arr1, arr2, arr3;
    printf("**Insert arrays in sorted order**");

    printf("\n\nFor 1st array, number of elements (maximum 10 elements) = ");
    scanf("%d", &arr1.length);
    printf("Enter the element(s) : ");
    for(int i = 0; i < arr1.length; i++){
        scanf("%d", &arr1.A[i]);
    }

    printf("\nFor 2nd array, number of elements (maximum 10 elements) = ");
    scanf("%d", &arr2.length);
    printf("Enter the element(s) : ");
    for(int i = 0; i < arr2.length; i++){
        scanf("%d", &arr2.A[i]);
    }

    printf("\nThe merged array : ");
    arr3 = merge(arr1, arr2);
    display(arr3);
    printf("The union of the arrays : ");
    arr3 = getUnion(arr1, arr2);
    display(arr3);
    printf("The intersection of the arrays : ");
    arr3 = getIntersection(arr1, arr2);
    display(arr3);
    printf("The difference of the arrays : ");
    arr3 = getDifference(arr1, arr2);
    display(arr3);
    return 0;
}
