/*
Syntax => std :: set <objectType, orderOfSorting> name;
Syntax => std :: multiset <objectType, orderOfSorting> name;

Notes:

1. Set is an associative container that contains a sorted set of unique elements
2. It stores elements in sorted order
3. It is usually implemented using 'Red-Black Tree'
4. Insert, delete, search operations have logarithmic complexity
5. To store user defined data types, we have to provide compare() function in order to store them in sorted order
6. We can pass order of sorting(greater/less) while constructing a set object
7. MultiSet is similar to set except that it can have multiple elements with same value
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    set <int, std :: greater <int>> st = {1, 2, 5, 4, 3, 2, 4, 1, 3, 5};
    cout << "Set :";
    for(auto& x : st){
        cout << " " << x;
    }
    cout << '\n';

    multiset <int> mst = {1, 2, 5, 4, 3, 2, 4, 1, 3, 5}; //default order of sorting is less
    cout << "Multiset :";
    for(auto& x : mst){
        cout << " " << x;
    }
    cout << '\n';
    return 0;
}

/*
Set : 5 4 3 2 1
Multiset : 1 1 2 2 3 3 4 4 5 5
*/
