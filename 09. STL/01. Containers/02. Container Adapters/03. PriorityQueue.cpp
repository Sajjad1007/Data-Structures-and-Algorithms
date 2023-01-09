/*
Syntax => std :: priority_queue <objectType, containerType, orderOfSorting> name;

Notes:

1. Priority queue is a container adapter that provides constant time lookup of the largest or smallest element
2. By default, vector is the container used inside
3. Internally it is implementation of a min-heap or a max-heap
4. Cost of insertion or extraction is logarithmic
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector <int> vec = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

    priority_queue <int> pq;
    for(int x : vec) pq.push(x);

    cout << "Priority queue in descending order :";
    while(!pq.empty()){ //we cannot iterate over a priority_queue
        cout << " " << pq.top();
        pq.pop();
    }
    cout << '\n';

    priority_queue <int, deque <int>, std :: greater <int>> qq;
    for(int x : vec) qq.push(x);

    cout << "Priority queue in  ascending order :";
    while(!qq.empty()){
        cout << " " << qq.top();
        qq.pop();
    }
    cout << '\n';
    return 0;
}

/*
Priority queue in descending order : 9 8 7 6 5 4 3 2 1 0
Priority queue in  ascending order : 0 1 2 3 4 5 6 7 8 9
*/
