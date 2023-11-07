#include <iostream>

using namespace std;

class LowerTriangular
{
private:
    int n;
    int *arr;

public:
    LowerTriangular()
    {
        n = 2;
        arr = new int[(n * (n + 1)) / 2];
    }

    LowerTriangular(int dim)
    {
        n = dim;
        arr = new int[(n * (n + 1)) / 2];
    }

    ~LowerTriangular()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i >= j){
            return arr[(i * (i - 1) / 2) + (j - 1)];             //Formula for storing in row major mapping
        }
        //If we replace i with j in this formula we'll get the formula for storing a upper triangular matrix in column major mapping.
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
        if(i >= j){
            arr[(i * (i - 1) / 2) + (j - 1)] = val;
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
    cout << "Dimension of the lower triangular matrix : ";
    cin >> dim;
    LowerTriangular lt(dim);

    cout << "\nEnter the non-zero elements of the matrix\n\n";
    for(i = 1; i <= dim; i++){
        for(j = 1; j <= i; j++){
            cin >> val;
            lt.Set(i, j, val);
        }
    }

    cout << "\nThe lower triangular matrix\n\n";
    lt.display();
    return 0;
}

/*
Dimension of the lower triangular matrix : 3

Enter the non-zero elements of the matrix

1
2 3
4 5 6

The lower triangular matrix

 1  0  0
 2  3  0
 4  5  6
*/
