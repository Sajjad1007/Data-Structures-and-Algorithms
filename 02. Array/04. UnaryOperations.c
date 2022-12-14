#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

int getElement(struct array arr, int index)
{
    return arr.A[index];
}

void setElement(struct array *ptr, int index, int val)
{
    if(index >= 0 && index < ptr->length){
        ptr->A[index] = val;
    }
    return;
}

int getMax(struct array arr)
{
    int i, max = arr.A[0];
    for(i = 1; i < arr.length; i++){
        if(max < arr.A[i]) max = arr.A[i];
    }
    return max;
}

int getMin(struct array arr)
{
    int i, min = arr.A[0];
    for(i = 1; i < arr.length; i++){
        if(min > arr.A[i]) min = arr.A[i];
    }
    return min;
}

int getSum(struct array arr)
{
    int i, sum = 0;
    for(i = 0; i < arr.length; i++) sum += arr.A[i];
    return sum;
}

float getAverage(struct array arr)
{
    float avg = (float)getSum(arr)/arr.length;
    return avg;
}

void display(struct array arr)
{
    printf("The array : ");
    for(int i = 0; i < arr.length; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    struct array arr = {{2, 3, 4, 5, 6}, 10, 5};
    int pos;

    display(arr);
    printf("\nEnter a position for getting the element : ");
    scanf("%d", &pos);
    if(pos > 0 && pos <= arr.length){
        printf("%d is at position %d\n", getElement(arr, pos-1), pos); //position = index+1
    }
    else printf("Invalid position\n");

    printf("\nEnter a position for setting an element : ");
    scanf("%d", &pos);

    if(pos > 0 && pos <= arr.length){
        int val;
        printf("Enter an element at position %d : ", pos);
        scanf("%d", &val);
        setElement(&arr, pos-1, val);
    }
    else printf("Invalid position");

    printf("\n");
    display(arr);

    printf("\nMaximum element of the array = %d\n", getMax(arr));
    printf("Minimum element of the array = %d\n", getMin(arr));
    printf("\nSum of all the elements = %d\n", getSum(arr));
    printf("Average of the elements = %g\n", getAverage(arr));
    return 0;
}

/*
interactive console window:

The array : 2 3 4 5 6

Enter a position for getting the element : 4
5 is at position 4

Enter a position for setting an element : 2
Enter an element at position 2 : 8

The array : 2 8 4 5 6

Maximum element of the array = 8
Minimum element of the array = 2

Sum of all the elements = 25
Average of the elements = 5
*/
