#include <iostream>

using namespace std;

class Symmetric
{
private:
    int n;
    int *arr;

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
        if(i < j)
        {
            int temp = i;
            i = j;
            j = temp;
        }
        return arr[(i*(i-1)/2)+(j-1)];
    }

    int get_dimension()
    {
        return n;
    }

    void Set(int i, int j, int val)
    {
        if(i < j)
        {
            int temp = i;
            i = j;
            j = temp;
        }
        arr[(i*(i-1)/2)+(j-1)] = val;
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
    cout << "Dimension of the symmetric matrix : ";
    cin >> dim;
    Symmetric s(dim);

    cout << "\nEnter the lower triangular elements of the matrix\n\n";
    for(i = 1; i <= dim; i++)
    {
        for(j = 1; j <= i; j++)
        {
            cin >> val;
            s.Set(i, j, val);
        }
    }

    cout << "\nThe symmetric matrix\n\n";
    s.display();
    return 0;
}

/*
Dimension of the symmetric matrix : 3

Enter the lower triangular elements of the matrix

1
2 3
4 5 6

The symmetric matrix

 1  2  4
 2  3  5
 4  5  6
*/
