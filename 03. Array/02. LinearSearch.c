//Time complexity is O(n)

#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int linearSearch(struct array *ptr, int key)
{
    for(int i = 0; i < ptr->length; i++){
        if(key == ptr->A[i]){
            /** 2 time shortening technique for further searching
            (a) Transposition
                swap(&ptr->A[i], &ptr->A[i-1]);
            (b) Move-to-head
                swap(&ptr->A[i], &ptr->A[0]);
            **/
            return i;
        }
    }
    return -1;
}

void display(struct array arr)
{
    printf("The array :");
    for(int i = 0; i < arr.length; i++){
        printf(" %d", arr.A[i]);
    }
    printf("\n\n");
    return;
}

int main(void)
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    int pos, key;
    display(arr);

    printf("Enter an element for searching : ");
    scanf("%d", &key);
    pos = linearSearch(&arr, key) + 1;

    if(pos >= 1){
        printf("\n%d is at position %d\n", key, pos);
    }
    else printf("\n%d not found\n", key);
    return 0;
}

/*
The array : 2 3 4 5 6

Enter an element for searching : 5

5 is at position 4
*/
