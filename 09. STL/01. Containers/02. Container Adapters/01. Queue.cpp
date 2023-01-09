/*
Syntax => std :: queue <objectType> name;

Notes:

1. Queue is a container adapter that gives the programmer the functionality of a queue
2. It is FIFO(first-in-first-out) data structure
3. It allows to push at back and pop from front
*/

#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue <int> q)
{
    //we cannot iterate over a queue
    while(!q.empty()){
        cout << " " << q.front();
        q.pop();
    }
    cout << '\n';
    return;
}

int main()
{
    queue <int> q;
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "The given queue :";
    printQueue(q);
    return 0;
}

/*
The given queue : 2 3 4
*/
