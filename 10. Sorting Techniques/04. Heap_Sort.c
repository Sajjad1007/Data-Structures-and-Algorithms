/*
Heap is a complete binary tree where each node is greater/less than all of its descendants.

Notes:

1. Comparison based sorting technique
2. Not adaptive(takes greater amount of time over already sorted list)
3. Unstable(changes the relative order of duplicate elements after sorting)
4. Space complexity O(1)
5. Best and worst case time complexity O(nlogn)
*/

#include <stdio.h>

int n = 8;               // Actually 7 elements will be there in the array.

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Time complexity of insertion is O(nlogn).
void Insert(int p[])
{
    for(int i = 1; i < n; i++)
    {
        int temp = p[i];
        while (i > 1 && temp > p[i/2])
        {
            p[i] = p[i/2];
            i /= 2;
        }
        p[i] = temp;
    }
    return;
}

// Time complexity of heapify is O(n).
void heapify(int q[])
{
    int i, j;
    for(i = (n-1)/2; i >= 1; i--)
    {
        j = 2*i;                        // Left child q[i]
        while(j < n)
        {
            if(q[j] < q[j+1])
            {
                j++;                    // Compare left and right children of q[i].
            }
            if(q[i] < q[j])             // Compare parent and largest child.
            {
                swap(&q[i], &q[j]);
                i = j;
                j = 2*i;
            }
            else
            {
                break;
            }
        }
    }
    return;
}

// Time complexity of deletion is O(nlogn).
void Delete(int t[])
{
    int temp_n;
    for(temp_n = n-1; temp_n > 0; temp_n--)
    {
        int i = 1, j = i*2;
        swap(&t[i], &t[temp_n]);

        while(j < temp_n)
        {
            if(j < temp_n-1 && t[j] < t[j+1])
            {
                j++;
            }
            if(t[i] < t[j])
            {
                swap(&t[i], &t[j]);
                i = j;
                j = i*2;
            }
            else
            {
                break;
            }
        }
    }
    return;
}

// This display() function traverses a heap level by level.
void display(int t[])
{
    for(int i = 1; i < n; i++)
    {
        printf(" %d", t[i]);
    }
    printf("\n");
    return;
}

int main(void)
{
    int i, arr[] = {0, 5, 10, 30, 20, 35, 40, 15};     // 0th index will not be used in heap sort.
    int p[n], q[n];

    for(i = 0; i < n; i++)                             // Elements are stored from index 1.
    {
        p[i] = q[i] = arr[i];
    }
    printf("The array :");
    display(arr);

    Insert(p);
    printf("\nInsertion method");
    printf("\n\nMax heap  :");
    display(p);
    Delete(p);
    printf("Heap sort :");
    display(p);

    printf("\nHeapify method");
    heapify(q);
    printf("\n\nMax heap  :");
    display(q);
    Delete(q);
    printf("Heap sort :");
    display(q);
    return 0;
}

/*
The array : 5 10 30 20 35 40 15

Insertion method

Max heap  : 40 30 35 5 20 10 15
Heap sort : 5 10 15 20 30 35 40

Heapify method

Max heap  : 40 35 30 20 10 5 15
Heap sort : 5 10 15 20 30 35 40
*/
