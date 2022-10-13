#include <iostream>

using namespace std;

class TriDiagonal
{

private:
    int *arr;
    int n;

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
        if(i == j+1) return arr[i-2];
        else if(i == j) return arr[n+i-2];
        else if(i == j-1) return arr[(2*n)+i-2];
        else return 0;
    }

    int getDimension()
    {
        return n;
    }

    void set(int i, int j, int val)
    {
        if(i == j+1) arr[i-2] = val;
        else if(i == j) arr[n+i-2] = val;
        else if(i == j-1) arr[(2*n)+i-2] = val;
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
    cout << "Dimension of the tri-diagonal matrix : ";
    cin >> dim;
    TriDiagonal td(dim);

    cout << "\nEnter the lower diagonal elements of the matrix :\n\n";
    for(int i = 2, j = 1; i <= dim; i++){
        cin >> val;
        td.set(i, j, val);
        j++;
    }

    cout << "\nEnter the diagonal elements of the matrix :\n\n";
    for(int i = 1, j = 1; i <= dim; i++){
        cin >> val;
        td.set(i, j, val);
        j++;
    }

    cout << "\nEnter the upper diagonal elements of the matrix :\n\n";
    for(int i = 1, j = 2; i < dim; i++){
        cin >> val;
        td.set(i, j, val);
        j++;
    }

    cout << "\nThe tri-diagonal matrix :\n\n";
    td.display();
    return 0;
}
