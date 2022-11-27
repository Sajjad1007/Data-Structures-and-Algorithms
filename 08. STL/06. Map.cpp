/*
Syntax => std :: map <keyType, valueType, orderOfSorting> name;
Syntax => std :: multimap <keyType, valueType, orderOfSorting> name;

Notes:

1. Map is an associative container that store elements in key-value pairs.
2. Key should be unique, otherwise it override the previous value.
3. It is implemented using 'Self-Balanced Binary Search Tree'(AVL/Red-Black Tree).
4. It stores pairs in sorted order on the basis of key(ascending/descending).
5. Map is generally used in dictionary type problems.
6. Key value cannot be changed once it has been initialized.
7. Multimap is similar to map except that it permits multiple entries with the same key.
8. We do not have at() and [] functions to get element like we have in map.
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    map <string, int, std::greater <string>> mp;
    mp["Chotu"] = 123;
    mp["Amit"] = 456;
    mp.insert(make_pair("Bot", 789));

    for(auto& x : mp){
        cout << x.first << " " << x.second << '\n';
    }
    cout << '\n';

    multimap <char, int> mmp;
    mmp.insert(make_pair('a', 1));
    mmp.insert(make_pair('a', 2));
    mmp.insert(make_pair('a', 3));
    mmp.insert(make_pair('b', 4));
    mmp.insert(make_pair('b', 5));

    for(auto& x : mmp){
        cout << x.first << " " << x.second << '\n';
    }

    cout << "\nNumber of values of a = " << mmp.count('a') << '\n';
    //get all the pairs of given key
    auto range = mmp.equal_range('a'); //equal_range() returns a pair of two iterators
    //range.first holds address of the first value of 'a'
    //range.second holds address of the last value of 'a'
    for(auto it = range.first; it != range.second; ++it){
        cout << it->first << " " << it->second << '\n';
    }
    return 0;
}