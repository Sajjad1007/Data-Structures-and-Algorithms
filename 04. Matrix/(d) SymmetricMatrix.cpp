#include <iostream>

using namespace std;

class Symmetric
{

private:
    int *arr;
    int n;

public:
    Symmetric()
    {
        n = 2;
        arr = new int[(n*(n+1))/2];
    }

    Symmetric(int dim)
    {
        n = dim;
        arr = new int[(n*(n+1))/2];
    }

    ~Symmetric()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i < j){
            int temp = i;
            i = j;
            j = temp;
        }
        return arr[(i*(i-1)/2)+(j-1)];
    }

    int getDimension()
    {
        return n;
    }

    void set(int i, int j, int val)
    {
        if(i < j){
            int temp = i;
            i = j;
            j = temp;
        }
        arr[(i*(i-1)/2)+(j-1)] = val;
        return;
    }

    void display()
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout.width(2);
                cout.setf(ios::adjustfield);
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
        return;
    }

};

int main()
{
    int dim, val;
    cout << "Dimension of the symmetric matrix : ";
    cin >> dim;
    Symmetric s(dim);

    cout << "\nEnter the lower diagonal elements of the matrix :\n\n";
    for(int i = 1; i <= dim; i++){
        for(int j = 1; j <= i; j++){
            cin >> val;
            s.set(i, j, val);
        }
    }

    cout << "\nThe symmetric matrix :\n\n";
    s.display();
    return 0;
}
