// Double Ended Queue is an extension of circular queue.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

int deque[MAX];
int frnt = -1;
int rear = -1;

bool empty()
{
    if(frnt == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool full()
{
    if((frnt == 0 && rear == MAX-1) || (frnt == rear+1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push_front(int val)
{
    if(full())
    {
        printf("\nQueue overflow\n");
        exit(1);
    }

    if(empty())
    {
        frnt = rear = 0;
    }
    else if(frnt == 0)
    {
        frnt = MAX-1;
    }
    else
    {
        --frnt;
    }
    deque[frnt] = val;
    return;
}

void push_back(int val)
{
    if(full())
    {
        printf("\nQueue overflow\n");
        exit(1);
    }

    if(empty())
    {
        frnt = rear = 0;
    }
    else if(rear == MAX-1)
    {
        rear = 0;
    }
    else
    {
        ++rear;
    }
    deque[rear] = val;
    return;
}

void pop_front()
{
    if(empty())
    {
        printf("\nQueue underflow\n");
        exit(1);
    }

    if(frnt == rear)
    {
        frnt = rear = -1;               // The last element has been popped from the queue.
    }
    else if(frnt == MAX-1)
    {
        frnt = 0;
    }
    else
    {
        ++frnt;
    }
    return;
}

void pop_back()
{
    if(empty())
    {
        printf("\nQueue underflow\n");
        exit(1);
    }

    if(frnt == rear)
    {
        frnt = rear = -1;
    }
    else if(rear == 0)
    {
        rear = MAX-1;
    }
    else
    {
        --rear;
    }
    return;
}

int Front()
{
    return deque[frnt];
}

int Rear()
{
    return deque[rear];
}

void display()
{
    if(empty())
    {
        printf("\nThe queue is empty\n");
        return;
    }

    printf("\nThe queue :");
    int i = frnt;

    while(i != rear)
    {
        printf(" %d", deque[i]);
        if(i == MAX-1)
        {
            i = 0;
        }
        else
        {
            ++i;
        }
    }
    printf(" %d\n", deque[rear]);
    return;
}

void choice_list()
{
    printf("Menu\n");
    printf("1. Push at front\n");
    printf("2. Push at rear\n");
    printf("3. Pop from front\n");
    printf("4. Pop from rear\n");
    printf("5. Print the front element\n");
    printf("6. Print the rear element\n");
    printf("7. Quit\n");
    return;
}

int main(void)
{
    int ch, val;
    printf("The queue has been initialized\n\n");

    while(true)
    {
        choice_list();
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter the element : ");
                scanf("%d", &val);
                push_front(val);
                display();
                break;

            case 2:
                printf("Enter the element : ");
                scanf("%d", &val);
                push_back(val);
                display();
                break;

            case 3:
                pop_front();
                display();
                break;

            case 4:
                pop_back();
                display();
                break;

            case 5:
                if(empty())
                {
                    printf("\nThe queue is empty\n");
                }
                else
                {
                    printf("\nThe front element is %d\n", Front());
                }
                break;

            case 6:
                if(empty())
                {
                    printf("\nThe queue is empty\n");
                }
                else
                {
                    printf("\nThe rear element is %d\n", Rear());
                }
                break;

            case 7:
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
