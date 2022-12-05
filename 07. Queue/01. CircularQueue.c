#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue{
    int size;
    int front;
    int rear;
    int *Q;
} q;

void create(int sz)
{
    q.front = q.rear = -1;
    q.size = sz;
    q.Q = (int*)malloc(sz*sizeof(int));
    return;
}

bool isEmpty()
{
    if(q.front == -1) return true;
    else return false;
}

bool isFull()
{
    if((q.front == 0 && q.rear == q.size-1) || (q.front == q.rear+1)) return true;
    else return false;
}

void enqueue(int data)
{
    if(q.front == -1) q.front = 0;
    q.rear = (q.rear + 1) % q.size;
    q.Q[q.rear] = data;
    return;
}

int dequeue()
{
    int data = q.Q[q.front];
    if(q.front == q.rear) q.front = q.rear = -1;
    else q.front = (q.front + 1) % q.size;
    return data;
}

int peek(int pos)
{
    pos = (q.front+pos-1) % q.size;
    return q.Q[pos];
}

int queueFront()
{
    return q.Q[q.front];
}

void display()
{
    printf("The queue :");
    int i = q.front;
    while(i != q.rear){
        printf(" %d", q.Q[i]);
        i = (i+1) % q.size;
    }
    printf(" %d\n", q.Q[q.rear]);
    return;
}

void printChoiceList()
{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print the front element\n");
    printf("4. Print any element\n");
    printf("5. Quit\n");
    return;
}

int main(void)
{
    int sz, choice, data, pos;
    printf("Enter size of the queue = ");
    scanf("%d", &sz);
    create(sz);
    printf("The queue has been initialized\n\n");

    while(true){
        printChoiceList();
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(!isFull()){
                    printf("Enter the element to be enqueued : ");
                    scanf("%d", &data);
                    enqueue(data);
                    printf("\n%d is enqueued successfully\n", data);
                    display();
                }
                else printf("\nQueue overflow\n");
                break;

            case 2:
                if(!isEmpty()){
                    printf("\nDeleted element is %d\n", dequeue());
                    if(!isEmpty()) display();
                    else printf("The queue is empty\n");
                }
                else printf("\nThe queue is empty\n");
                break;

            case 3:
                if(!isEmpty()) printf("\nThe front element is %d\n", queueFront());
                else printf("\nThe queue is empty\n");
                break;

            case 4:
                if(!isEmpty()){
                    printf("Enter the position : ");
                    scanf("%d", &pos);
                    if(pos > q.size || pos <= 0) printf("\nInvalid position\n");
                    else printf("\nThe element at position %d is %d\n", pos, peek(pos));
                }
                else printf("\nThe queue is empty\n");
                break;

            case 5:
                printf("\nFee Amanillah\n");
                return 0;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
        printf("\n");
    }
}
