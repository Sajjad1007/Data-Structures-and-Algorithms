/*
Syntax => std :: priority_queue <objectType, containerType, orderOfSorting> name;

Notes:

1. Priority queue is a container adapter that provides constant time lookup of the
   largest or smallest element.
2. By default, vector is the container used inside.
3. Internally it is implementation of a min-heap or a max-heap.
4. Cost of insertion or extraction is logarithmic.
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector <int> v = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    priority_queue <int> pq;
    for(int x : v) pq.push(x);
    while(!pq.empty()){ //we cannot iterate over a priority_queue
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';

    priority_queue <int, deque <int>, std::greater <int>> qq;
    for(int x : v) qq.push(x);
    while(!qq.empty()){
        cout << qq.top() << " ";
        qq.pop();
    }
    return 0;
}