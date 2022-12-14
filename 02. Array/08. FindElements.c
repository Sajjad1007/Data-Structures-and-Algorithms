#include <stdio.h>

struct array{
    int A[10];
    int size;
};

void getMaxMin(struct array arr, int* max, int* min)
{
    *max = *min = arr.A[0];
    for(int i = 1; i < arr.size; i++){
        if(arr.A[i] < *min) *min = arr.A[i];
        else if(arr.A[i] > *max) *max = arr.A[i];
    }
    return;
}

//This function will find missing elements in a sorted array of n consecutive numbers
void findMissingElementSorted(struct array arr)
{
    int i, diff = arr.A[0];
    if(arr.A[0] != arr.A[arr.size-1]-(arr.size-1)){
        printf("Missing element(s) :");
    }
    else{
        printf("No elements are missing\n");
        return;
    }

    for(i = 1; i < arr.size;){
        if(arr.A[i] - i != diff){
            printf(" %d", i+diff);
            diff++;
            continue;
        }
        i++;
    }
    printf("\n\n");
    return;
}

//This function will find missing elements in both sorted and unsorted array
void findMissingElementUnsorted(struct array arr)
{
    int max, min, i;
    getMaxMin(arr, &max, &min);
    int hash[max+1];

    if(min != max-(arr.size-1)){
        printf("Missing element(s) :");
    }
    else{
        printf("No elements are missing\n");
        return;
    }

    for(i = min; i <= max; i++) hash[i] = 0;
    for(i = 0; i < arr.size; i++) hash[arr.A[i]] = 1;
    for(i = min; i <= max; i++){
        if(hash[i] == 0) printf(" %d", i);
    }
    printf("\n\n");
    return;
}

void getDuplicatesSorted(struct array arr)
{
    int i, j;
    printf("Duplicate element(s) :");
    for(i = 0; i < arr.size-1; i++){
        if(arr.A[i] == arr.A[i+1]){
            j = i+1;
            while(arr.A[i] == arr.A[j]) j++; //j will be increased until we get a new element
            printf("  %d (%d times)", arr.A[i], j-i);
            i = j-1;
        }
    }
    printf("\n\n");
    return;
}

void getDuplicatesUnsorted(struct array arr)
{
    int max, min, i;
    getMaxMin(arr, &max, &min);
    int hash[max+1];

    printf("Duplicate element(s) :");
    for(i = min; i <= max; i++) hash[i] = 0;
    for(i = 0; i < arr.size; i++) hash[arr.A[i]]++;
    for(i = min; i <= max; i++){
        if(hash[i] > 1){
            printf("  %d (%d times)", i, hash[i]);
        }
    }
    printf("\n\n");
    return;
}

void findPairSorted(struct array arr)
{
    int i = 0, j = arr.size-1;
    int sum = 10;

    printf("The pair(s) are :");
    while(i < j){
        if(arr.A[i]+arr.A[j] == sum){
            printf(" (%d, %d)", arr.A[i], arr.A[j], sum);
            i++; j--;
        }
        else if(arr.A[i]+arr.A[j] < sum) i++;
        else j--;
    }
    printf("\n\n");
    return;
}

void findPairUnsorted(struct array arr)
{
    int max, min, i;
    getMaxMin(arr, &max, &min);
    int hash[max+1], sum = 10;

    printf("The pair(s) are :");
    for(i = min; i <= max; i++) hash[i] = 0;
    for(i = 0; i < arr.size; i++){
        if(hash[sum-arr.A[i]] == 1){
            int min = arr.A[i] < sum-arr.A[i] ? arr.A[i] : sum-arr.A[i];
            printf(" (%d, %d)", min, sum-min); //printing the smaller element first
        }
        hash[arr.A[i]] = 1;
    }
    printf("\n");
    return;
}

void display(struct array arr)
{
    for(int i = 0; i < arr.size; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    struct array arrMissingSorted = {{6, 7, 8, 9, 10, 11, 13, 14, 15, 16}, 10};
    struct array arrMissingUnsorted = {{3, 7, 4, 9, 12, 6, 1, 11, 2, 10}, 10};
    struct array arrDuplicateSorted = {{3, 6, 8, 8, 10, 12, 15, 15, 15, 20}, 10};
    struct array arrDuplicateUnsorted = {{8, 3, 6, 4, 6, 5, 6, 8, 2, 7}, 10};
    struct array arrPairSorted = {{1, 3, 4, 5, 6, 8, 9, 10, 12, 14}, 10};
    struct array arrPairUnsorted = {{6, 3, 8, 10, 16, 7, 5, 2, 9, 14}, 10};

    printf("The sorted array   : ");
    display(arrMissingSorted);
    findMissingElementSorted(arrMissingSorted);

    printf("The unsorted array : ");
    display(arrMissingUnsorted);
    findMissingElementUnsorted(arrMissingUnsorted);

    printf("The sorted array     : ");
    display(arrDuplicateSorted);
    getDuplicatesSorted(arrDuplicateSorted);

    printf("The unsorted array   : ");
    display(arrDuplicateUnsorted);
    getDuplicatesUnsorted(arrDuplicateUnsorted);

    printf("\nIn each pair, sum of the elements is equal to 10\n\n\n");
    printf("The sorted array : ");
    display(arrPairSorted);
    findPairSorted(arrPairSorted);

    printf("The unsorted array : ");
    display(arrPairUnsorted);
    findPairUnsorted(arrPairUnsorted);
    return 0;
}

/*
interactive console window:

The sorted array   : 6 7 8 9 10 11 13 14 15 16
Missing element(s) : 12

The unsorted array : 3 7 4 9 12 6 1 11 2 10
Missing element(s) : 5 8

The sorted array     : 3 6 8 8 10 12 15 15 15 20
Duplicate element(s) :  8 (2 times)  15 (3 times)

The unsorted array   : 8 3 6 4 6 5 6 8 2 7
Duplicate element(s) :  6 (3 times)  8 (2 times)


In each pair, sum of the elements is equal to 10


The sorted array : 1 3 4 5 6 8 9 10 12 14
The pair(s) are : (1, 9) (4, 6)

The unsorted array : 6 3 8 10 16 7 5 2 9 14
The pair(s) are : (3, 7) (2, 8)
*/
