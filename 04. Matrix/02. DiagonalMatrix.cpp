#include <iostream>

using namespace std;

class Diagonal
{

private:
    int *arr;
    int n;

public:
    Diagonal()
    {
        n = 2;
        arr = new int[n];
    }

    Diagonal(int dim)
    {
        n = dim;
        arr = new int[n];
    }

    ~Diagonal()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i == j) return arr[i-1];
        else return 0;
    }

    void set(int i, int j, int val)
    {
        if(i == j) arr[i-1] = val;
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
            cout << '\n';
        }
        return;
    }

};

int main()
{
    int i, dim, val;
    cout << "Dimension of the diagonal matrix : ";
    cin >> dim;
    Diagonal d(dim);

    cout << "\nEnter the diagonal elements of the matrix :\n\n";
    for(i = 1; i <= dim; i++){
        cin >> val;
        d.set(i, i, val);
    }

    cout << "\nThe diagonal matrix :\n\n";
    d.display();
    return 0;
}
