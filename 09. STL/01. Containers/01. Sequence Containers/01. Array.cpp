/*
Syntax => std :: array <objectType, size> name;

Notes:

1. Array is a sequence container that encapsulates fixed size arrays
2. Size of the array is needed at compile time
3. Calling a function with pass by value is possible
4. Access elements: at(), [], front(), back()
5. data() returns address of the internal array inside the class 'array'
*/

#include <iostream>
#include <array>

using namespace std;

void printArray(array <int, 5> arr)
{
    for(auto& x : arr){
        cout << " " << x;
    }
    cout << '\n';
    return;
}

int main()
{
    //declaration
    array <int, 5> arr1;

    //initialization
    array <int, 5> arr2 = {0, 1, 2, 3, 4}; //initializer list
    array <int, 5> arr3 {5, 6, 7, 8, 9}; //uniform initialiation

    //assigning values using initializer list
    arr1 = {2, 3, 4, 5, 6};

    cout << "Array 1 :";
    printArray(arr1);
    cout << "Array 2 :";
    printArray(arr2);
    cout << "Array 3 :";
    printArray(arr3);
    return 0;
}

/*
Array 1 : 2 3 4 5 6
Array 2 : 0 1 2 3 4
Array 3 : 5 6 7 8 9
*/
