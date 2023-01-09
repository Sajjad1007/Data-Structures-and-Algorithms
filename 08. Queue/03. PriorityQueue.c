#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
} *q;

void create(struct queue *p, int sz)
{
    p->front = p->rear = -1;
    p->size = sz;
    p->Q = (int *)malloc(sz * sizeof(int));
    return;
}

bool isEmpty(struct queue p)
{
    if(p.front == -1) return true;
    else return false;
}

bool isFull(struct queue p)
{
    if((p.front == 0 && p.rear == p.size - 1) || (p.front == p.rear + 1)) return true;
    else return false;
}

void insert(struct queue *p, int data)
{
    if(p->front == -1) p->front = 0;
    p->rear = (p->rear + 1) % p->size;
    p->Q[p->rear] = data;
    return;
}

int dequeue(struct queue *p)
{
    int data = p->Q[p->front];
    if(p->front == p->rear) p->front = p->rear = -1;
    else p->front = (p->front + 1) % p->size;
    return data;
}

void display()
{
    for(int j = 0; j < 3; j++){
        if(isEmpty(q[j])){
            printf("\nPriority-%d queue is empty", j + 1);
            continue;
        }

        printf("\nPriority-%d queue :", j + 1);
        int i = q[j].front;
        while(i != q[j].rear){
            printf(" %d", q[j].Q[i]);
            i = (i + 1) % q[j].size;
        }
        printf(" %d", q[j].Q[q[j].rear]);
    }
    printf("\n");
    return;
}

void printChoiceList()
{
    printf("Menu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Quit\n");
    return;
}

int main(void)
{
    int i, sz, choice, data, pos, prio;
    printf("Enter size of each queue = ");
    scanf("%d", &sz);

    q = (struct queue *)malloc(3 * sizeof(struct queue));
    for(i = 0; i < 3; i++) create(&q[i], sz);
    printf("The queue has been initialized (with 1 to 3 priorities)\n\n");

    while(true){
        printChoiceList();
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element and priority : ");
                scanf("%d %d", &data, &prio);
                if(!isFull(q[prio - 1])){
                    insert(&q[prio - 1], data);
                    printf("\n%d has been inserted to Priority-%d queue\n", data, prio);
                }
                else printf("\nPriority-%d queue overflow\n", prio);
                display();
                break;

            case 2:
                for(int i = 0; i < 3; i++){
                    if(!isEmpty(q[i])){
                        printf("\n%d has been deleted\n", dequeue(&q[i]));
                        break;
                    }
                }
                display();
                break;

            case 3:
                printf("\nFee Amanillah\n");
                return 0;

            default:
                printf("\nInvalid choice\n");
                break;
        }
        printf("\n");
    }
}

/*
Menu driven program
*/
