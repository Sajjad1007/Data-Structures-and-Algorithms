/*
Syntax => std :: deque <objectType> name;

Notes:

1. Deque(Double Ended Queue) is an indexed sequence container
2. It allows fast insertion at both beginning and end
3. Unlike vector, elements of deque are not stored contiguous
4. It uses individual allocated fixed size array with additional bookkeeping, that means index based access to deque must perform
   two pointer dereference, but in vector we get the vaue in one dereference
5. The storage of a deque is automatically expanded and contracted as needed
6. Expansion of deque is more efficient than expansion of vector
7. Time complexity :
   (a) Random access = O(1)
   (b) Insertion or removal of elements at the end or begining = O(1)
   (c) Insertion or removal of other elements = O(n)
*/

#include <iostream>
#include <deque>

using namespace std;

void printDeque(deque <int> dq)
{
    for(auto& x : dq){
        cout << " " << x;
    }
    cout << '\n';
    return;
}

int main()
{
    deque <int> dq = {2, 3, 4};
    cout << "The given Deque :";
    printDeque(dq);

    dq.pop_front();
    dq.pop_back();
    cout << "\nDeque after popping :";
    printDeque(dq);

    dq.push_front(1);
    dq.push_back(9);
    cout << "Deque after pushing :";
    printDeque(dq);
    return 0;
}

/*
The given Deque : 2 3 4

Deque after popping : 3
Deque after pushing : 1 3 9
*/
