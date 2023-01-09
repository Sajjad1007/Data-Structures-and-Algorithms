/*
Prerequisite : The array must be in sorted order
Time complexity is O(log(n + 1))
*/

#include <stdio.h>

struct array{
    int A[10];
    int size;
    int length;
};

int binarySearch(int ara[], int key, int low, int high)
{
    while(low <= high){
        int mid = (low + high) / 2;

        if(key == ara[mid]) return mid;
        else if(key < ara[mid]) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

//Tail recursion and loops are similar
int rbinarySearch(int ara[], int key, int low, int high)
{
    if(low > high) return -1;

    int mid = (low + high) / 2;

    if(key == ara[mid]) return mid;
    else if(key < ara[mid]){
        return(rbinarySearch(ara, key, low, mid - 1));
    }
    else{
        return(rbinarySearch(ara, key, mid + 1, high));
    }
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
    pos = binarySearch(arr.A, key, 0, arr.length - 1) + 1;
    printf("\nIterative => ");

    if(pos >= 1) printf("%d is at position %d\n", key, pos);
    else printf("%d not found\n", key);

    pos = rbinarySearch(arr.A, key, 0, arr.length - 1) + 1;
    printf("Recursive => ");

    if(pos >= 1) printf("%d is at position %d\n", key, pos);
    else printf("%d not found\n", key);
    return 0;
}

/*
The array : 2 3 4 5 6

Enter an element for searching : 5

Iterative => 5 is at position 4
Recursive => 5 is at position 4
*/
