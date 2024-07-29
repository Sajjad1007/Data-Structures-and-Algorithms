#include <stdio.h>
#include <stdbool.h>

#define MAX 32

int stack[MAX];
int top = -1;

bool empty()
{
    return (top == -1);
}

void push(int data)
{
    stack[++top] = data;
    return;
}

int pop()
{
    return stack[top--];
}

void decimal_to_binary(int num)
{
    if(num == 0)
    {
        printf("0\n");
        return;
    }

    while(num != 0)
    {
        push(num%2);
        num /= 2;
    }

    while(!empty())
    {
        printf("%d", pop());
    }
    printf("\n");
    return;
}

int main(void)
{
    int num;
    printf("Enter a decimal number : ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("\nError 404 not found.\n");
        return 0;
    }
    printf("\nBinary equivalent of %d = ", num);
    decimal_to_binary(num);
    return 0;
}

/*
Enter a decimal number : 203

Binary equivalent of 203 = 11001011
*/
