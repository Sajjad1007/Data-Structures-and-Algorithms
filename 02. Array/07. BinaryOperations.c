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
        else arr3.A[k++] = arr2.A[j++];
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
        else if(arr1.A[i] < arr2.A[j]) i++;
        else j++;
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
        else if(arr1.A[i] > arr2.A[j]) j++;
        else{ i++; j++; }
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
        if(i == arr.length - 1) printf("%d}", arr.A[i]);
        else printf("%d, ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    struct array arr1 = {{1, 3, 5, 7, 9}, 5};
    struct array arr2 = {{1, 2, 3, 4, 5}, 5};
    struct array arr3;

    printf("Set A : {");
    display(arr1);
    printf("Set B : {");
    display(arr2);
    printf("\n**The sets are in sorted order**\n");

    printf("\nA merge B      : {");
    arr3 = merge(arr1, arr2);
    display(arr3);
    printf("A union B      : {");
    arr3 = getUnion(arr1, arr2);
    display(arr3);
    printf("A intersect B  : {");
    arr3 = getIntersection(arr1, arr2);
    display(arr3);
    printf("A minus B      : {");
    arr3 = getDifference(arr1, arr2);
    display(arr3);
    return 0;
}

/*
Set A : {1, 3, 5, 7, 9}
Set B : {1, 2, 3, 4, 5}

**The sets are in sorted order**

A merge B      : {1, 1, 2, 3, 3, 4, 5, 5, 7, 9}
A union B      : {1, 2, 3, 4, 5, 7, 9}
A intersect B  : {1, 3, 5}
A minus B      : {7, 9}
*/
