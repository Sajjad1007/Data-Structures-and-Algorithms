/*
Syntax => std :: forward_list <objectType> name;
Syntax => std :: list <objectType> name;

Notes:

1. Forward list is similar to the singly linked list and list is similar to the doubly linked list of C programming language
2. List and forward_list are sequence containers that allow non-contiguous memory location
3. List is faster compared to other sequence containers(vector/forward_list/deque) in terms of insertion, deletion and moving
   elements in any position provided that we have the iterator of the position
4. We should use list/forward_list instead of traditional singly/doubly linked list because
   (a) it is well tested
   (b) it has a bunch of available functions
*/

#include <iostream>
#include <forward_list>
#include <list>

using namespace std;

void printForwardList(forward_list <int> list)
{
    for(auto& x : list){
        cout << " " << x;
    }
    cout << '\n';
    return;
}

int main()
{
    forward_list <int> list1 = {5, 4, 6, 2};
    forward_list <int> list2 = {7, 6, 1, 9};

    list1.insert_after(list1.begin(), 8);
    list2.resize(7);

    cout << "List 1 :";
    printForwardList(list1);
    cout << "List 2 :";
    printForwardList(list2);

    list1.sort(); //list1 = {2, 4, 5, 6, 8}
    list2.sort(); //list2 = {0, 0, 0, 1, 6, 7, 9}
    list1.merge(list2);
    cout << "\nList 1 merge  List 2 :";
    printForwardList(list1); //list2 is empty

    list <int> list3 = {5, 2, 4, 6};
    list <int> list4 = {7, 6, 1, 9};
    list3.splice(list3.begin(), list4);

    cout << "List 3 splice List 4 :";
    for(auto& x : list3){
        cout << " " << x;
    }
    cout << '\n';
    return 0;
}

/*
List 1 : 5 8 4 6 2
List 2 : 7 6 1 9 0 0 0

List 1 merge  List 2 : 0 0 0 1 2 4 5 6 6 7 8 9
List 3 splice List 4 : 7 6 1 9 5 2 4 6
*/
