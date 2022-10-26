#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node{
    char data;
    struct node *next;
} *top = NULL;

bool isEmpty()
{
    if(top == NULL) return true;
    else return false;
}

void push(char data)
{
    struct node *t = (struct node*)malloc(sizeof(struct node));
    t->data = data;
    t->next = top;
    top = t;
    return;
}

char pop()
{
    char data = top->data;
    struct node *t = top;
    top = top->next;

    free(t);
    t = NULL;
    return data;
}

bool isBalanced(char *expr)
{
    for(int i = 0; i < strlen(expr); i++){
        if(expr[i] == '(' || expr[i] == '{' || expr[i] == '[') push(expr[i]);
        else if(expr[i] == ')' || expr[i] == '}' || expr[i] == ']'){
            if(isEmpty()) return false;
            else{
                char ch = pop();
                if(ch == '(' && expr[i] == ')');
                else if(ch == '{' && expr[i] == '}');
                else if(ch == '[' && expr[i] == ']');
                else return false;
            }
        }
    }
    return isEmpty() ? true : false;
}

int main(void)
{
    char expr[51];
    printf("Enter the algebraic expression (maximum 50 characters) : ");
    gets(expr);
    if(isBalanced(expr)) printf("\nBrackets are well balanced\n");
    else printf("\nBrackets are not balanced\n");
    return 0;
}
