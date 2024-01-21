#include <iostream>

using namespace std;

struct node
{
    int col;
    int val;
    node *next;

    node()
    {
        next = nullptr;
    }

    node(int col, int val)
    {
        this->col = col;
        this->val = val;
        next = nullptr;
    }
};

class Sparse
{
public:
    int rows;
    int cols;
    int nodes;
    node **arr;

    Sparse(int r, int c, int n)
    {
        rows = r;
        cols = c;
        nodes = n;
        arr = new node*[n];

        for(int i = 0; i < n; i++)
        {
            arr[i] = nullptr;
        }
    }

    ~Sparse()
    {
        delete arr;
        arr = nullptr;
    }

    void create()
    {
        int i, row, col, val;
        cout << "\nEnter row no, column no and non-zero elements\n\n";
        for(i = 0; i < nodes; i++)
        {
            cin >> row >> col >> val;
            node *p = arr[row-1];

            if(p == nullptr)
            {
                arr[row-1] = new node(col, val);
            }
            else
            {
                while(p->next)
                {
                    p = p->next;
                }
                p->next = new node(col, val);
            }
        }
        return;
    }

    void display()
    {
        int i, j;
        for(i = 0; i < rows; i++)
        {
            node *p = arr[i];
            for(j = 1; j <= cols; j++)
            {
                if(p != nullptr && j == p->col)
                {
                    printf("%2d ", p->val);
                    p = p->next;
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

int main()
{
    int r, c, n;
    cout << "Enter dimensions of the sparse matrix : ";
    cin >> r >> c;
    cout << "Number of non-zero elements = ";
    cin >> n;
    Sparse s(r, c, n);

    if(n > 0)
    {
        s.create();
    }
    cout << "\nThe sparse matrix\n\n";
    s.display();
    return 0;
}

/*
Enter dimensions of the sparse matrix : 2 2
Number of non-zero elements = 4

Enter row no, column no and non-zero elements

1 1 1
1 2 2
2 1 3
2 2 1

The sparse matrix

 1  2
 3  1
*/
