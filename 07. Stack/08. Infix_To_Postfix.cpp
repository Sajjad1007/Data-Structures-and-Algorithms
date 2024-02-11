/*
Infix means that the operator is written in between two operands, postfix means that the operator is written after two operands.
Computers prefer postfix expressions instead of infix expressions.

Algorithm 1. To convert an expression from infix to postfix using stack

Scan the symbols of the given infix expression from left to right and for each symbol, do any the following :

If the symbol is an operand then
- Copy it into the postfix expression.

Else if the symbol is an operator then
- If the stack is not empty
    - Pop all the operators from the stack which are of greater than or equal to the symbol precedence and copy them into the postfix expression.
- Push that symbol onto the stack.

Else if the symbol is a left parenthesis then
- Push it onto the stack.

Else if the symbol is a right parenthesis then
- Pop all the operators from the stack up to the first left parenthesis and copy them into the postfix expression.
- Discard the current left parenthesis.

At the end, pop all the operators from the stack and copy them into the postfix expression.

This is the postfix expression obtained from the given infix expression.


Algorithm 2. To evaluate a postfix expression using stack

Scan the symbols of the given postfix expression from left to right and for each symbol, do any the following :

If the symbol is an operand then
- Push it onto the stack.

Else if the symbol is an operator then
- Pop two operands from the stack and perform the operation on them according to their respective order.
- Push the result onto the stack.

After scanning all the symbols of the postfix expression,
- Pop the remaining operand from the stack.

This is the result obtained after evaluating the postfix expression.
*/

#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>

#define MAX 101

using namespace std;

stack <int> s;                // First the operators, then the operands will be pushed onto the stack.
char infix[MAX];
char postfix[MAX];

bool space(char c)
{
    if(c == ' ' || c == '\t')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char symbol)
{
    switch(symbol)
    {
    case '^':
        return 3;

    case '/':
    case '*':
        return 2;

    case '+':
    case '-':
        return 1;

    default:
        return 0;
    }
}

void infix_to_postfix()
{
    int i = 0, j = 0;
    int len = strlen(infix);
    char symbol, next;

    while(i < len)
    {
        symbol = infix[i++];
        if(!space(symbol))
        {
            switch(symbol)
            {
            default:          // When symbol is an operand
                postfix[j++] = symbol;
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                while(!s.empty() && (precedence(s.top()) >= precedence(symbol)))
                {
                    if(symbol == '^')
                    {
                        break;
                    }
                    postfix[j++] = s.top();
                    s.pop();
                }
                s.push(symbol);
                break;

            case '(':
                s.push(symbol);
                break;

            case ')':
                next = s.top();
                s.pop();
                while(next != '(')
                {
                    postfix[j++] = next;
                    next = s.top();
                    s.pop();
                }
                break;
            }
        }
    }

    while(!s.empty())
    {
        postfix[j++] = s.top();         // The stack becomes empty.
        s.pop();
    }
    postfix[j] = '\0';
    return;
}

int postfix_evaluation()
{
    int i = 0, a, b;

    while(postfix[i] != '\0')
    {
        if(postfix[i] >= '0' && postfix[i] <= '9')
        {
            s.push(postfix[i++]-'0');
        }
        else
        {
            b = s.top();
            s.pop();
            a = s.top();
            s.pop();

            switch(postfix[i++])
            {
            case '+':
                s.push(a+b);
                break;

            case '-':
                s.push(a-b);
                break;

            case '*':
                s.push(a*b);
                break;

            case '/':
                s.push(a/b);
                break;

            case '^':         // The associativity of this operator is right to left.
                s.push(pow(a, b));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    int result;
    cout << "Enter the infix expression : ";
    gets(infix);
    infix_to_postfix();
    result = postfix_evaluation();
    cout << "\nThe equivalent postfix expression : " << postfix << "\n";
    cout << "The result obtained after postfix evaluation : " << result << "\n";
    return 0;
}

/*
Enter the infix expression : (8+7)*(6-3)/9+(2*7-4)/5

The equivalent postfix expression : 87+63-*9/27*4-5/+
The result obtained after postfix evaluation : 7
*/
