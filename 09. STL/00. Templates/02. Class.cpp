#include <iostream>

using namespace std;

template <typename T>
class Rectangle{

private:
    T length;
    T breadth;

public:
    Rectangle(T length)
    {
        this->length = length;
        this->breadth = length;
    }

    Rectangle(T length, T breadth)
    {
        if(length < breadth){
            length = length + breadth;
            breadth = length - breadth;
            length = length - breadth;
        }
        this->length = length;
        this->breadth = breadth;
    }

    T area();
    T perimeter();

    T getLength()
    {
        return length;
    }

    void setLength(T length)
    {
        if(length < breadth) return;
        this->length = length;
    }

    T getBreadth()
    {
        return breadth;
    }

    void setBreadth(T breadth)
    {
        if(breadth > length) return;
        this->breadth = breadth;
    }

    ~Rectangle()
    {
        cout << "The rectangle is destructed\n";
    }

};

template <typename T>
T Rectangle <T> :: area()
{
    return length * breadth;
}

template <typename T>
T Rectangle <T> :: perimeter()
{
    return 2 * (length + breadth);
}

int main()
{
    double length, breadth;
    cout << "Enter length and breadth of the rectangle : ";
    cin >> length >> breadth;

    Rectangle <double> rec(length, breadth);
    cout << "\nLength = " << rec.getLength() << '\n';
    cout << "Breadth = " << rec.getBreadth() << '\n';
    cout << "\nArea = " << rec.area() << '\n';
    cout << "Perimeter = " << rec.perimeter() << "\n\n";
    return 0;
}

/*
Enter length and breadth of the rectangle : 5 3.6

Length = 5
Breadth = 3.6

Area = 18
Perimeter = 17.2

The rectangle is destructed
*/
