#include <iostream>

using namespace std;

class TriDiagonal
{
private:
    int n;
    int *arr;

public:
    TriDiagonal()
    {
        n = 2;
        arr = new int[(3*n)-2];
    }

    TriDiagonal(int dim)
    {
        n = dim;
        arr = new int[(3*n)-2];
    }

    ~TriDiagonal()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i == j+1){
            return arr[i-2];
        }
        else if(i == j)
        {
            return arr[n+i-2];
        }
        else if(i == j-1)
        {
            return arr[(2*n)+i-2];
        }
        else
        {
            return 0;
        }
    }

    int get_dimension()
    {
        return n;
    }

    void Set(int i, int j, int val)
    {
        if(i == j+1)
        {
            arr[i-2] = val;
        }
        else if(i == j)
        {
            arr[n+i-2] = val;
        }
        else if(i == j-1)
        {
            arr[(2*n)+i-2] = val;
        }
        return;
    }

    void display()
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
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
    cout << "Dimension of the tri-diagonal matrix : ";
    cin >> dim;
    TriDiagonal td(dim);

    cout << "\nEnter the lower diagonal elements of the matrix\n\n";
    for(i = 2, j = 1; i <= dim; i++)
    {
        cin >> val;
        td.Set(i, j, val);
        j++;
    }

    cout << "\nEnter the diagonal elements of the matrix\n\n";
    for(i = 1, j = 1; i <= dim; i++)
    {
        cin >> val;
        td.Set(i, j, val);
        j++;
    }

    cout << "\nEnter the upper diagonal elements of the matrix\n\n";
    for(i = 1, j = 2; i < dim; i++)
    {
        cin >> val;
        td.Set(i, j, val);
        j++;
    }

    cout << "\nThe tri-diagonal matrix\n\n";
    td.display();
    return 0;
}

/*
Dimension of the tri-diagonal matrix : 5

Enter the lower diagonal elements of the matrix

1 2 3 4

Enter the diagonal elements of the matrix

5 5 5 5 5

Enter the upper diagonal elements of the matrix

6 7 8 9

The tri-diagonal matrix

 5  6  0  0  0
 1  5  7  0  0
 0  2  5  8  0
 0  0  3  5  9
 0  0  0  4  5
*/
