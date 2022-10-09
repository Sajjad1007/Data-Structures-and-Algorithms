#include <iostream>

using namespace std;

template <class T>
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

    void insertElement(int index, T val)
    {
        for(int i = length; i > index; i--){
            A[i] = A[i-1];
        }
        A[index] = val;
        length++;
        return;
    }

    T deleteElement(int index)
    {
        T val = A[index];
        for(int i = index; i < length-1; i++){
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

template <class T>
void Array<T>::display()
{
    cout << "\nThe array : ";
    for(int i = 0; i < length; i++){
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    Array <float> arr;
    float val;
    int size, length, choice, pos;

    cout << "Size of the array = ";
    cin >> size;
    cout << "Length of the array = ";
    cin >> length;
    if(length > size){
        cout << "\nLength cannot be greater than size\nTry again" << endl;
        return 0;
    }

    arr = Array<float>(size);
    cout << "Enter " << length << " element(s) : ";
    for(int i = 0; i < length; i++){
        cin >> arr.A[i];
        arr.plusLength();
    }

    do{
        cout << "\nMenu" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Sum & average" << endl;
        cout << "4. Exit\n" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch(choice){
            case 1:
                if(size == arr.getLength()){
                    cout << "\nThe array is full" << endl;
                    break;
                }

                cout << "Enter the position : ";
                cin >> pos;
                if(pos < 0 || pos > (arr.getLength()+1)){
                    cout << "\nPlease enter a valid position" << endl;
                    break;
                }
                else{
                    cout << "Enter the element : ";
                    cin >> val;
                    arr.insertElement(pos-1, val);
                    arr.display();
                    break;
                }

            case 2:
                cout << "Enter the position : ";
                cin >> pos;
                if(pos < 0 || pos > (arr.getLength()+1)){
                    cout << "\nPlease enter a valid position" << endl;
                    break;
                }
                else{
                    val = arr.deleteElement(pos-1);
                    cout << "\nDeleted element : " << val;
                    arr.display();
                }
                break;

            case 3:
                cout << "\nSum = " << arr.getSum() << endl;
                cout << "Average = " << arr.getAverage() << endl;
                break;

            case 4:
                cout << "\nThank you!" << endl;
                break;
        }
    } while(choice < 4);
    return 0;
}
