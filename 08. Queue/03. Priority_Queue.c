#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    struct node *next;
} node;

node *frnt = NULL;            // 'rear' pointer will not be needed in case of priority queue.

bool empty()
{
    return (frnt == NULL);
}

void push(int val)
{
    node *t = (node *)malloc(sizeof(node));
    t->val = val;
    t->next = NULL;

    if(empty() || (val > frnt->val))
    {
        t->next = frnt;
        frnt = t;
    }
    else
    {
        node *p = frnt;
        while((p->next != NULL) && (p->next->val >= val))
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
    return;
}

void pop()
{
    if(empty())
    {
        printf("\nQueue underflow\n");
        exit(1);
    }

    node *p = frnt;
    frnt = frnt->next;
    free(p);
    p = NULL;
    return;
}

int Front()
{
    return frnt->val;
}

void display()
{
    if(empty())
    {
        printf("\nThe queue is empty.\n");
        return;
    }

    node *p = frnt;
    printf("\nThe queue :");

    while(p)
    {
        printf(" %d", p->val);
        p = p->next;
    }
    printf("\n");
    return;
}

int main(void)
{
    int ch, val;
    printf("The queue has been initialized.\n\n");

    while(true)
    {
        printf("Menu\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the front element\n");
        printf("4. Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("Enter the element : ");
                scanf("%d", &val);
                push(val);
                display();
                break;

            case 2:
                pop();
                display();
                break;

            case 3:
                if(empty())
                {
                    printf("\nThe queue is empty.\n");
                }
                else
                {
                    printf("\nThe front element is %d.\n", Front());
                }
                break;

            case 4:
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
