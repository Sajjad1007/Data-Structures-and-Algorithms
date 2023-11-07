#include <iostream>
#include <stack>

#define MAX 5

using namespace std;

stack <int> s;

void reverse_stack()
{
    stack <int> s1, s2;
    //Pushing onto temporary stack 1
    while(!s.empty()){
        s1.push(s.top());
        s.pop();
    }

    //Pushing onto temporary stack 2
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }

    //Pushing onto original stack
    while(!s2.empty()){
        s.push(s2.top());
        s2.pop();
    }
    return;
}

void display()
{
    stack <int> st = s;
    while(!st.empty()){
        cout << " " << st.top();
        st.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    int n, data;
    cout << "The stack has been initialized\n\n";
    cout << "Enter " << MAX << " elements in the stack : ";
    for(int i = 1; i <= MAX; i++){
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
