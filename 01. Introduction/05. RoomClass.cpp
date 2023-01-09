#include <iostream>

using namespace std;

class Room{

private:
    double length;
    double width;
    double height;

public:
    Room()
    {
        length = 1;
        width = 1;
        height = 1;
    }

    Room(double length, double width, double height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }

    double calculateArea()
    {
        return length * width;
    }

    double calculateVolume()
    {
        return length * width * height;
    }

    double getLength()
    {
        return length;
    }

    double getWidth()
    {
        return width;
    }

    double getHeight()
    {
        return height;
    }

    void setLength(double length)
    {
        if(this->length > 0) this->length = length;
        return;
    }

    void setWidth(double width)
    {
        if(this->width > 0) this->width = width;
        return;
    }

    void setHeight(double height)
    {
        if(this->height > 0) this->height = height;
        return;
    }

};

int main()
{
    Room room1; //in C++, objects does not need to be initialized using new
    Room room2(2, 1.5, 1.2); //a variable has been initialized, not a pointer
    Room room3 = room2; //value of the object has been copied, not address
    Room *room4 = new Room(5, 4, 3);
    Room *room5 = room4;

    cout << "Before altering the values...\n\n";
    cout << "Area of the room 1 = " << room1.calculateArea() << endl;
    cout << "Area of the room 2 = " << room2.calculateArea() << endl;
    cout << "Area of the room 3 = " << room3.calculateArea() << endl;
    cout << "Area of the room 4 = " << room4->calculateArea() << endl;
    cout << "Area of the room 5 = " << room5->calculateArea() << endl;

    room3.setLength(3);
    room5->setLength(6.2);

    cout << "\n\nAfter altering the values...\n\n";
    cout << "Area of the room 1 = " << room1.calculateArea() << endl;
    cout << "Area of the room 2 = " << room2.calculateArea() << endl;
    cout << "Area of the room 3 = " << room3.calculateArea() << endl;
    cout << "Area of the room 4 = " << room4->calculateArea() << endl;
    cout << "Area of the room 5 = " << room5->calculateArea() << endl;
    cout << endl;
    return 0;
}

/*
Before altering the values...

Area of the room 1 = 1
Area of the room 2 = 3
Area of the room 3 = 3
Area of the room 4 = 20
Area of the room 5 = 20


After altering the values...

Area of the room 1 = 1
Area of the room 2 = 3
Area of the room 3 = 4.5
Area of the room 4 = 24.8
Area of the room 5 = 24.8
*/
