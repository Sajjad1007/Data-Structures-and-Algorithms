#include <iostream>
#include <cstring>
#include <stack>

#define MAX 101

using namespace std;

bool space(char c)
{
    if(c == ' ' || c == '\t'){
        return true;
    }
    else{
        return false;
    }
}

bool left_parenthesis(char c)
{
    switch(c)
    {
        case '[':
        case '{':
        case '(':
            return true;

        default:
            return false;
    }
}

bool right_parenthesis(char c)
{
    switch(c)
    {
        case ']':
        case '}':
        case ')':
            return true;

        default:
            return false;
    }
}

bool matched(char a, char b)
{
    if(a == '[' && b == ']'){
        return true;
    }
    else if(a == '{' && b == '}'){
        return true;
    }
    else if(a == '(' && b == ')'){
        return true;
    }
    else{
        return false;
    }
}

bool balanced(char *str)
{
    int len = strlen(str);
    stack <char> s;

    for(int i = 0; i < len; i++){
        if(!space(str[i])){
            if(left_parenthesis(str[i])){
                s.push(str[i]);
            }
            else if(right_parenthesis(str[i])){
                if(s.empty()){
                    cout << "Right brackets are more than left brackets\n";
                    return false;
                }
                else if(!matched(s.top(), str[i])){
                    cout << "Mismatched brackets\n";
                    return false;
                }
                else{
                    s.pop();
                }
            }
        }
    }

    if(s.empty()){
        return true;
    }
    else{
        cout << "Left brackets are more than right brackets\n";
        return false;
    }
}

int main()
{
    char expr[MAX];
    cout << "Enter the algebraic expression : ";
    scanf(" %[^\n]", expr);
    cout << "\n";
    if(balanced(expr)){
        cout << "Brackets are well balanced\n";
    }
    return 0;
}

/*
Enter the algebraic expression : {a+b*[c/d]-(a+d)}

Brackets are well balanced
*/
