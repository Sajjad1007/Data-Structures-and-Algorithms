//Time Complexity of Heap sort = O(nlogn)

#include <stdio.h>
#include <stdlib.h>

int *p = NULL; //array for insertion
int *q = NULL; //array for heapify

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//Time complexity of insertion = O(nlogn)
void insert(int i)
{
    int temp = p[i];
    while (i > 1 && temp > p[i/2]){ //for min heap, we have to place '<' in this line
        p[i] = p[i/2]; //we are assuming that index starts from 1
        i = i/2;
    }
    p[i] = temp;
    return;
}

//Time complexity of heapify = O(n)
void heapify(int n)
{
    int i, j;
    for(i = n/2; i >= 1; i--){
        j = 2*i; //left child p[i]
        while(j <= n-1){
            if(q[j] < q[j+1]) j++; //compare left and right children of q[i]
            if(q[i] < q[j]){ //compare parent and largest child
                swap(&q[i], &q[j]);
                i = j;
                j = 2*i;
            }
            else break;
        }
    }
    return;
}

//Time complexity of deletion = O(nlogn)
void delete(int *t, int n)
{
    int i = 1, j = i*2;
    swap(&t[1], &t[n]);

    while(j <= n-1){
        if(j < n-1 && t[j] < t[j+1]) j++;
        if(t[i] < t[j]){
            swap(&t[i], &t[j]);
            i = j;
            j *= 2;
        }
        else break;
    }
    return;
}

int main(void)
{
    int i, n;
    printf("Number of elements = ");
    scanf("%d", &n);
    p = (int*)malloc((n+1)*sizeof(int));
    q = (int*)malloc((n+1)*sizeof(int));
    p[0] = q[0] = 0;

    printf("Enter %d elements : ", n);
    for(i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        q[i] = p[i];
        insert(i);
    }

    printf("\nMax heap (insertion) :");
    for(i = 1; i <= n; i++) printf(" %d", p[i]);
    heapify(n);
    printf("\nMax heap (heapify)   :");
    for(i = 1; i <= n; i++) printf(" %d", q[i]);

    for(i = n; i >= 1; i--){
        delete(p, i);
        delete(q, i);
    }

    printf("\n\nAfter heap sort (insertion) :");
    for(i = 1; i <= n; i++) printf(" %d", p[i]);
    printf("\nAfter heap sort (heapify)   :");
    for(i = 1; i <= n; i++) printf(" %d", q[i]);
    printf("\n");
    return 0;
}
