#include <stdio.h>
#include <math.h>
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
    struct node *t = NULL;
    t = (struct node*)malloc(sizeof(struct node));
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

char stackTop()
{
    return top->data;
}

bool isOperand(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return false;
    default:
        return true;
    }
}

bool isBracket(char c)
{
    if(c == '(' || c == ')') return true;
    else return false;
}

int precedence(char c)
{
    if(c == '^') return 3;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}

char *infixToPostfix(char *infix)
{
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char*)malloc((len+1)*sizeof(char));

    while(infix[i] != '\0'){
        if(isBracket(infix[i])){
            if(infix[i] == '(') push(infix[i++]);
            else{
                char ch = pop();
                while(ch != '('){
                    postfix[j++] = ch;
                    ch = pop();
                }
                i++;
            }
        }
        else if(isOperand(infix[i])) postfix[j++] = infix[i++];
        else{
            if(isEmpty() || (precedence(infix[i]) > precedence(top->data))) push(infix[i++]);
            else if(infix[i] == '^') push(infix[i++]);
            else postfix[j++] = pop();
        }
    }

    while(top != NULL) postfix[j++] = pop();
    postfix[j] = '\0';
    return postfix;
}

int postfixEvaluation(char *postfix)
{
    int a, b, i;
    for(i = 0; postfix[i] != '\0'; i++){
        if(isOperand(postfix[i])) push(postfix[i]-'0');
        else{
            b = pop();
            a = pop();
            switch(postfix[i])
            {
            case '+':
                push(a+b);
                break;

            case '-':
                push(a-b);
                break;

            case '*':
                push(a*b);
                break;

            case '/':
                push(a/b);
                break;

            case '^':
                push(pow(a,b));
                break;
            }
        }
    }
    return pop();
}

int main(void)
{
    int result;
    char infix[100];
    printf("Enter the infix expression : ");
    gets(infix);
    char *postfix = infixToPostfix(infix);
    result = postfixEvaluation(postfix);
    printf("\nThe equivalent postfix expression : %s\n", postfix);
    printf("The result obtained after postfix evaluation : %d\n", result);
    return 0;
}
