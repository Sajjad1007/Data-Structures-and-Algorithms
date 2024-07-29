#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

bool palindrome(char *str)
{
    int i = 0, len = strlen(str);
    stack<char> s;

    while(i < len/2)
    {
        s.push(str[i++]);          // Push half of the string onto stack.
    }

    if(len%2 != 0)
    {
        ++i;
    }

    while(str[i])
    {
        if(s.empty() || str[i++] != s.top())
        {
            return false;
        }
        s.pop();
    }
    return (s.empty());
}

int main()
{
    char str[100];
    cout << "Enter a string : ";
    cin >> str;

    if(palindrome(str))
    {
        cout << "\n\"" << str << "\" is a palindrome.\n";
    }
    else
    {
        cout << "\n\"" << str << "\" is not a palindrome.\n";
    }
    return 0;
}

/*
Enter a string : abbccbab

"abbccbab" is not a palindrome.
*/
