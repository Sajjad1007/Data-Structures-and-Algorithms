/*
Template is the way to write generic programs.
Here we pass data type as parameter to function or class.
*/

#include <iostream>

using namespace std;

int const& max(int const& a, int const& b)
{
    cout << "max(int, int)" << '\n';
    return a > b ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b)
{
    cout << "max(T, T)" << '\n';
    return a > b ? a : b;
}

template <typename T>
T const& max(T const& a, T const& b, T const& c)
{
    cout << "max(T, T, T)" << '\n';
    return max(max(a, b), c);
}

int main()
{
    //calling max() function of current scope
    :: max(10.0, 20.0);
    cout << '\n';

    //data type is deduced from parameter list
    :: max('a', 'b');
    cout << '\n';

    :: max(10, 20);
    cout << '\n';

    :: max<>(10, 20);
    cout << '\n';

    //explicit mention of data type
    :: max <double> (10.0, 20.0);
    cout << '\n';

    :: max(10, 20, 30);
    return 0;
}