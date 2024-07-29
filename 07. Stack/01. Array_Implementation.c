#include <stdio.h>
#include <stdlib.h>           // For exit(1) function
#include <stdbool.h>

#define MAX 5

int stack[MAX];
int top = -1;                 // Currently the stack is empty.

bool empty()
{
    return (top == -1);
}

bool full()
{
    return (top == MAX-1);
}

void push(int val)
{
    if(full())
    {
        printf("\nStack overflow\n");
        exit(1);              // exit(1) means abnormal termination of the program.
    }
    stack[++top] = val;
    return;
}

void pop()
{
    if(empty())
    {
        printf("\nStack underflow\n");
        exit(1);
    }
    stack[top--];
    return;
}

int Top()
{
    return stack[top];
}

void display()
{
    if(empty())
    {
        printf("\nThe stack is empty.\n");
        return;
    }

    printf("\nThe stack :");
    for(int i = top; i >= 0; --i)
    {
        printf(" %d", stack[i]);
    }
    printf("\n");
    return;
}

void choice_list()
{
    printf("Menu\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Print the top element\n");
    printf("4. Quit\n");
    return;
}

int main(void)
{
    int ch, val;
    printf("The stack has been initialized.\n\n");

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
                    printf("\nThe stack is empty.\n");
                }
                else
                {
                    printf("\nThe top element is %d.\n", Top());
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
