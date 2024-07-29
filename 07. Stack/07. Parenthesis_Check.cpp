#include <iostream>
#include <cstring>
#include <stack>

#define MAX 101

using namespace std;

bool space(char c)
{
    return (c == ' ' || c == '\t');
}

bool left_parenthesis(char c)
{
    return (c == '[' || c == '{' || c == '(');
}

bool right_parenthesis(char c)
{
    return (c == ']' || c == '}' || c == ')');
}

bool matched(char a, char b)
{
    return ((a == '[' && b == ']') || (a == '{' && b == '}') || (a == '(' && b == ')'));
}

bool balanced(char *str)
{
    stack<char> s;
    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        if(!space(str[i]))
        {
            if(left_parenthesis(str[i]))
            {
                s.push(str[i]);
            }
            else if(right_parenthesis(str[i]))
            {
                if(s.empty() || !matched(s.top(), str[i]))
                {
                    return false;
                }
                else
                {
                    s.pop();
                }
            }
        }
    }
    return (s.empty());
}

int main()
{
    char expr[MAX];
    cout << "Enter the algebraic expression : ";
    scanf(" %[^\n]", expr);
    cout << "\n";

    if(balanced(expr))
    {
        cout << "Brackets are well balanced.\n";
    }
    else
    {
        cout << "Brackets are not balanced.\n";
    }
    return 0;
}

/*
Enter the algebraic expression : {a+b*[c/d]-(a+d)}

Brackets are well balanced.
*/
