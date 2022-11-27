/*
Syntax => std :: pair <keyType, valueType> name;

Notes:

1. Pair is a struct template that provides a way to store two heterogeneous objects
   as a single unit.
2. Map, multimap, unorder_map, unorder_multimap can use pair to insert data
   into their structures.
*/

#include <iostream>
#include <vector>

using namespace std;

void printPair(pair <string, int> p)
{
    
    cout << p.first << " " << p.second << '\n';
    return;
}

int main()
{
    vector <pair <string, int>> vp;
    vp.push_back(make_pair("Rupesh", 30));
    vp.push_back(make_pair("Hitesh", 28));
    vp.push_back(pair <string, int> ("Bhupendra", 22));
    vp.push_back(make_pair("Rupesh", 30));

    for(auto& x : vp){
        printPair(x);
    }
    return 0;
}