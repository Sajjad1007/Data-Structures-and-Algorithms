#include <iostream>

using namespace std;

class UpperTriangular
{
private:
    int n;
    int *arr;

public:
    UpperTriangular()
    {
        n = 2;
        arr = new int[(n * (n + 1)) / 2];
    }

    UpperTriangular(int dim)
    {
        n = dim;
        arr = new int[(n * (n + 1)) / 2];
    }

    ~UpperTriangular()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i <= j){
            return arr[n * (i - 1) - ((i - 1) * (i - 2) / 2) + (j - i)];   //Formula for storing in row major mapping
        }
        //If we replace i with j in this formula we'll get the formula for storing a lower triangular matrix in column major mapping.
        else{
            return 0;
        }
    }

    int get_dimension()
    {
        return n;
    }

    void Set(int i, int j, int val)
    {
        if(i <= j){
            arr[n * (i - 1) - ((i - 1) * (i - 2) / 2) + (j - i)] = val;
        }
        return;
    }

    void display()
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                printf("%2d ", get(i, j));
            }
            cout << "\n";
        }
        return;
    }
};

int main()
{
    int i, j, dim, val;
    cout << "Dimension of the upper triangular matrix : ";
    cin >> dim;
    UpperTriangular ut(dim);

    cout << "\nEnter the non-zero elements of the matrix\n\n";
    for(i = 1; i <= dim; i++){
        for(j = i; j <= dim; j++){
            cin >> val;
            ut.Set(i, j, val);
        }
    }

    cout << "\nThe upper triangular matrix\n\n";
    ut.display();
    return 0;
}

/*
Dimension of the upper triangular matrix : 3

Enter the non-zero elements of the matrix

1 2 3
  4 5
    6

The upper triangular matrix

 1  2  3
 0  4  5
 0  0  6
*/
