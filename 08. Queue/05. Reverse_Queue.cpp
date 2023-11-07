#include <iostream>
#include <stack>
#include <queue>

#define MAX 5

using namespace std;

queue <int> q;
stack <int> s;

void reverse_queue()
{
    int data;
    //First dequeue elements from queue, then push them onto stack.
    while(!q.empty()){
        data = q.front();
        q.pop();
        s.push(data);
    }

    //First pop elements from stack, then enqueue them onto queue.
    while(!s.empty()){
        data = s.top();
        s.pop();
        q.push(data);
    }
    return;
}

void display()
{
    queue <int> qt = q;
    while(!qt.empty()){
        cout << " " << qt.front();
        qt.pop();
    }
    cout << "\n";
    return;
}

int main()
{
    int i, data;
    cout << "The queue has been initialized\n\n";
    cout << "Enter " << MAX << " elements in the queue : ";
    for(i = 1; i <= MAX; i++){
        cin >> data;
        q.push(data);
    }

    cout << "\nBefore reversing, the queue :";
    display();
    reverse_queue();
    cout << "After  reversing, the queue :";
    display();
    return 0;
}

/*
The queue has been initialized

Enter 5 elements in the queue : 1 2 3 4 5

Before reversing, the queue : 1 2 3 4 5
After  reversing, the queue : 5 4 3 2 1
*/
