#include <iostream>
#include <stack>
#include <queue>

#define MAX 5

using namespace std;

stack <int> s;
queue <int> q;

void reverse_stack()
{
    int data;

    // First pop elements from stack, then enqueue them onto queue.
    while(!s.empty())
    {
        data = s.top();
        s.pop();
        q.push(data);
    }

    // First dequeue elements from queue, then push them onto stack.
    while(!q.empty())
    {
        data = q.front();
        q.pop();
        s.push(data);
    }
    return;
}

void display()
{
    stack <int> st = s;

    while(!st.empty())
    {
        cout << " " << st.top();
        st.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    int i, data;
    cout << "The stack has been initialized\n\n";
    cout << "Enter " << MAX << " elements in the stack : ";
    for(i = 1; i <= MAX; i++)
    {
        cin >> data;
        s.push(data);
    }

    cout << "\nBefore reversing, the stack :";
    display();
    reverse_stack();
    cout << "After  reversing, the stack :";
    display();
    return 0;
}

/*
The stack has been initialized

Enter 5 elements in the stack : 1 2 3 4 5

Before reversing, the stack : 5 4 3 2 1
After  reversing, the stack : 1 2 3 4 5
*/
