#include <iostream>

using namespace std;

struct element
{
    int row;
    int col;
    int val;
};

class Sparse
{
public:
    int rows;
    int cols;
    int elem;
    element *e;

    Sparse(int r, int c, int n)
    {
        rows = r;
        cols = c;
        elem = n;
        e = new element[n];
    }

    ~Sparse()
    {
        e = nullptr;
    }

    void create()
    {
        cout << "\nEnter row no, column no and non-zero elements\n\n";
        for(int i = 0; i < elem; i++)
        {
            cin >> e[i].row >> e[i].col >> e[i].val;
        }
        return;
    }

    void display()
    {
        int i, j, k = 0;
        for(i = 0; i < rows; i++)
        {
            for(j = 0; j < cols; j++)
            {
                if(i == e[k].row-1 && j == e[k].col-1)
                {
                    printf("%2d ", e[k++].val);
                }
                else
                {
                    printf(" 0 ");
                }
            }
            cout << "\n";
        }
        return;
    }
};

Sparse add_matrices(Sparse s1, Sparse s2)
{
    Sparse sum(0, 0, 0);
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.e = new element[s1.elem+s2.elem];

    int i = 0, j = 0, k = 0;
    while(i < s1.elem && j < s2.elem)
    {
        if(s1.e[i].row < s2.e[j].row)
        {
            sum.e[k++] = s1.e[i++];
        }
        else if(s1.e[i].row > s2.e[j].row)
        {
            sum.e[k++] = s2.e[j++];
        }
        else
        {
            if(s1.e[i].col < s2.e[j].col)
            {
                sum.e[k++] = s1.e[i++];
            }
            else if(s1.e[i].col > s2.e[j].col)
            {
                sum.e[k++] = s2.e[j++];
            }
            else
            {
                sum.e[k] = s1.e[i++];
                sum.e[k++].val += s2.e[j++].val;
            }
        }
    }

    while(i < s1.elem)
    {
        sum.e[k++] = s1.e[i++];
    }
    while(j < s2.elem)
    {
        sum.e[k++] = s2.e[j++];
    }
    sum.elem = k;
    return sum;
}

int main()
{
    int r, c, n;
    cout << "Enter dimensions of 1st sparse matrix : ";
    cin >> r >> c;
    cout << "Number of non-zero elements : ";
    cin >> n;
    Sparse s1(r, c, n);
    if(n > 0)
    {
        s1.create();
    }

    cout << "\nEnter dimensions of 2nd sparse matrix : ";
    cin >> r >> c;
    cout << "Number of non-zero elements : ";
    cin >> n;
    Sparse s2(r, c, n);
    if(n > 0)
    {
        s2.create();
    }

    cout << "\n1st sparse matrix\n\n";
    s1.display();
    cout << "\n2nd sparse matrix\n\n";
    s2.display();

    if(s1.rows != s2.rows || s1.cols != s2.cols)
    {
        cout << "\nThe matrices are not addable.\n";
    }
    else
    {
        Sparse sum = add_matrices(s1, s2);
        cout << "\nSum of the matrices\n\n";
        sum.display();
    }
    return 0;
}

/*
Enter dimensions of 1st sparse matrix : 2 2
Number of non-zero elements : 4

Enter row no, column no and non-zero elements

1 1 1
1 2 2
2 1 3
2 2 1

Enter dimensions of 2nd sparse matrix : 2 2
Number of non-zero elements : 3

Enter row no, column no and non-zero elements

1 2 4
2 1 3
2 2 2

1st sparse matrix

 1  2
 3  1

2nd sparse matrix

 0  4
 3  2

Sum of the matrices

 1  6
 6  3
*/
