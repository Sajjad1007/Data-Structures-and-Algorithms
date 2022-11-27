/*
Syntax => std :: stack <objectType> name;

Notes:

1. Stack is a container adapter that gives the programmer the functionality of a stack.
2. Internally it uses deque STL container(that is why it is an adapter).
3. It is LIFO(last-in-first-out) data structure.
4. It allows to push and pop only from back.
5. If we want to use vector container instead of deque as adapter, we can declare stack like
   std :: stack <objectType, vector> name;
*/

#include <iostream>
#include <stack>

using namespace std;

void printStack(stack <int> s)
{
    //we cannot iterate over a stack
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return;
}

int main()
{
    stack <int> s;

    s.push(2);
    s.push(3);
    s.push(4);
    printStack(s);
    return 0;
}