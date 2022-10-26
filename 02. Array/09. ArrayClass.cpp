#include <iostream>

using namespace std;

template <typename T>
class Array
{

private:
    int size;
    int length;

public:
    T *A; //the array will be created dynamically

    Array()
    {
        this->size = 5;
        length = 0;
        A = new T[5];
    }

    Array(int size)
    {
        this->size = size;
        length = 0;
        A = new T[size];
    }

    ~Array()
    {
        delete[] A;
        A = nullptr;
    }

    int getLength()
    {
        return length;
    }

    void plusLength()
    {
        length++;
        return;
    }

    void insertElement(int pos, T val)
    {
        int i, index = pos-1;
        for(i = length; i > index; i--){
            A[i] = A[i-1];
        }
        A[index] = val;
        length++;
        return;
    }

    T deleteElement(int pos)
    {
        int i, index = pos-1;
        T val = A[index];
        for(i = index; i < length-1; i++){
            A[i] = A[i+1];
        }
        length--;
        return val;
    }

    T getSum()
    {
        T sum = 0;
        for(int i = 0; i < length; i++) sum += A[i];
        return sum;
    }

    float getAverage()
    {
        float avg = (float)getSum()/length;
        return avg;
    }

    void display();

};

template <typename T>
void Array<T> :: display()
{
    cout << "\nThe array : ";
    for(int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << '\n';
    return;
}

int main()
{
    Array <float> arr; //object variable has been created
    float val;
    int size, length, choice, pos;

    cout << "Size of the array = ";
    cin >> size;
    cout << "Length of the array = ";
    cin >> length;
    if(length > size){
        cout << "\nLength cannot be greater than size\nTry again\n";
        return 0;
    }

    arr = Array <float>(size); //object has been created and assigned to the variable
    cout << "\nThe array has been initialized\n\n";
    cout << "Enter " << length << " element(s) : ";
    for(int i = 0; i < length; i++){
        cin >> arr.A[i];
        arr.plusLength();
    }

    do{
        cout << "\nMenu\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Sum & average\n";
        cout << "4. Exit\n\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                if(size == arr.getLength()){
                    cout << "\nThe array is full\n";
                    break;
                }

                cout << "Enter the position : ";
                cin >> pos;
                if(pos <= 0 || pos > (arr.getLength()+1)){
                    cout << "\nPlease enter a valid position\n";
                    break;
                }
                else{
                    cout << "Enter the element : ";
                    cin >> val;
                    arr.insertElement(pos, val);
                    arr.display();
                    break;
                }

            case 2:
                cout << "Enter the position : ";
                cin >> pos;
                if(pos <= 0 || pos > (arr.getLength())){
                    cout << "\nPlease enter a valid position\n";
                    break;
                }
                else{
                    val = arr.deleteElement(pos);
                    cout << "\nDeleted element : " << val;
                    arr.display();
                }
                break;

            case 3:
                cout << "\nSum = " << arr.getSum() << '\n';
                cout << "Average = " << arr.getAverage() << '\n';
                break;

            case 4:
                cout << "\nJazakallahu Khairan!\n";
                break;
        }
    } while(choice < 4);
    return 0;
}
