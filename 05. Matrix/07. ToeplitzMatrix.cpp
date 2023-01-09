//Toeplitz matrix : elements in each diagonal are same

#include <iostream>

using namespace std;

class Toeplitz
{

private:
    int *arr;
    int n;

public:
    Toeplitz()
    {
        n = 2;
        arr = new int[(2 * n) - 1];
    }

    Toeplitz(int dim)
    {
        n = dim;
        arr = new int[(2 * n) - 1];
    }

    ~Toeplitz()
    {
        delete arr;
        arr = nullptr;
    }

    int get(int i, int j)
    {
        if(i <= j) return arr[j - i];
        else return arr[n + i - j - 1];
    }

    int getDimension()
    {
        return n;
    }

    void set(int i, int j, int val)
    {
        if(i <= j){
            for(; i <= n; i++, j++) arr[j - i] = val;
        }
        else{
            for(; i <= n; i++, j++) arr[n + i - j - 1] = val;
        }
        return;
    }

    void display()
    {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cout.width(2);
                cout.setf(ios :: adjustfield);
                cout << get(i, j) << " ";
            }
            cout << '\n';
        }
        return;
    }

};

int main()
{
    int i, j, dim, val;
    cout << "Dimension of the toeplitz matrix : ";
    cin >> dim;
    Toeplitz t(dim);

    cout << "\nEnter the first row of the matrix :\n\n";
    for(j = 1; j <= dim; j++){
        cin >> val;
        t.set(1, j, val);
    }

    cout << "\nEnter the first column of the matrix :\n\n" << t.get(1, 1) << " ";
    for(i = 2; i <= dim; i++){
        cin >> val;
        t.set(i, 1, val);
    }

    cout << "\nThe toeplitz matrix :\n\n";
    t.display();
    return 0;
}

/*
Dimension of the toeplitz matrix : 5

Enter the first row of the matrix :

1 2 3 4 5

Enter the first column of the matrix :

1 6 7 8 9

The toeplitz matrix :

 1  2  3  4  5
 6  1  2  3  4
 7  6  1  2  3
 8  7  6  1  2
 9  8  7  6  1
*/
