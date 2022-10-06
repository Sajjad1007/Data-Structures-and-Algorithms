#include <iostream>

using namespace std;

struct node
{
    int colNo;
    int value;
    node *next;

    node()
    {
        next = nullptr;
    }

    node(int col, int val)
    {
        colNo = col;
        value = val;
        next = nullptr;
    }
};

class Sparse
{

public:
    int numberOfRows;
    int numberOfCols;
    int numberOfNodes;
    node **arr;

    Sparse(int m, int n, int num)
    {
        numberOfRows = m;
        numberOfCols = n;
        numberOfNodes = num;
        arr = new node*[num];

        for(int i = 0; i < num; i++){
            arr[i] = nullptr;
        }
    }

    ~Sparse()
    {
        delete arr;
    }

    void create()
    {
        int row, col, val;
        cout << "\nEnter row no, column no and non-zero elements :\n\n";
        for(int i = 0; i < numberOfNodes; i++){
            cin >> row >> col >> val;
            node *p = arr[row-1];
            if(p == nullptr) arr[row-1] = new node(col, val);
            else{
                while(p->next) p = p->next;
                p->next = new node(col, val);
            }
        }
        return;
    }

    void display()
    {
        int i, j;
        for(i = 0; i < numberOfRows; i++){
            node *p = arr[i];
            for(j = 1; j <= numberOfCols; j++){
                cout.width(2);
                cout.setf(ios::adjustfield);
                if(p != nullptr && j == p->colNo){
                    cout << p->value << " ";
                    p = p->next;
                }
                else
                    cout << 0 << " ";
            }
            cout << endl;
        }
        return;
    }

};

int main()
{
    int m, n, num;

    cout << "Enter dimensions of the sparse matrix : ";
    cin >> m >> n;
    cout << "Number of non-zero elements = ";
    cin >> num;
    Sparse s(m, n, num);
    if(num > 0) s.create();

    cout << "\nThe sparse matrix :\n\n";
    s.display();
    return 0;
}

