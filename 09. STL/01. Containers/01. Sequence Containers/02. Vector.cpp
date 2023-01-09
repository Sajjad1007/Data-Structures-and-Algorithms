/*
Syntax => std :: vector <objectType> name;

Notes:

1. Vector is a sequence container and also known as 'Dynamic Array' or 'Array List'
2. Its size can grow and shrink dynamically, no need to provide size at compile time
3. Access elements by using at(), [], front(), back(), data()
*/

#include <iostream>
#include <vector>

using namespace std;

void printVector(vector <int> vec)
{
    for(auto& x : vec){
        cout << " " << x;
    }
    cout << '\n';
    return;
}

int main()
{
    //declaration
    vector <int> vec1;
    vec1.reserve(100);

    //initialization
    vector <int> vec2(5, 1); //(size, value)
    vector <int> vec3 = {0, 1, 2, 3, 4}; //initializer list
    vector <int> vec4 {5, 6, 7, 8, 9}; //uniform initialiation

    //assigning values using initializer list
    vec1 = {2, 3, 4, 5, 6};

    //accessing elements
    vec2.at(3) = 0; //exception safe
    vec2[3] = 0; //not exception safe, will show garbage value if IndexOutOfBoundException occurs

    cout << "Vector 1 :";
    printVector(vec1);
    cout << "Size = " << vec1.size() << ", Capacity = " << vec1.capacity() << "\n\n";

    cout << "Vector 2 :";
    printVector(vec2);
    cout << "Size = " << vec2.size() << ", Capacity = " << vec2.capacity() << "\n\n";

    cout << "Vector 3 :";
    printVector(vec3);
    cout << "Size = " << vec3.size() << ", Capacity = " << vec3.capacity() << "\n\n";

    cout << "Vector 4 :";
    printVector(vec4);
    cout << "Size = " << vec4.size() << ", Capacity = " << vec4.capacity() << '\n';
    return 0;
}

/*
Vector 1 : 2 3 4 5 6
Size = 5, Capacity = 100

Vector 2 : 1 1 1 0 1
Size = 5, Capacity = 5

Vector 3 : 0 1 2 3 4
Size = 5, Capacity = 5

Vector 4 : 5 6 7 8 9
Size = 5, Capacity = 5
*/
