#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int stack[MAX];
int top = -1;

bool empty()
{
    if(top == -1){
        return true;
    }
    else{
        return false;
    }
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

int Top()
{
    return stack[top];
}

void prime_fact(int num)
{
    while(num % 2 == 0){
        push(2);
        num /= 2;
    }

    int i = 3, copy;
    while(num != 1){
        while(num % i == 0){
            push(i);
            num /= i;
        }
        i += 2;
    }

    while(!empty()){
        copy = pop();
        if(copy != Top()){
            printf(" %d", copy);
        }
    }
    printf("\n");
    return;
}

int main(void)
{
    int num;
    printf("Enter a positive number : ");
    scanf("%u", &num);

    if(num <= 1){
        printf("\nError 404 not found\n");
        return 0;
    }
    printf("\nPrime factors of %d in descending order :", num);
    prime_fact(num);
    return 0;
}

/*
Enter a positive number : 1200

Prime factors of 1200 in descending order : 5 3 2
*/
