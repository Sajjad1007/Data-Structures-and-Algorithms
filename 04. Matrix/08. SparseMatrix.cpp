#include <iostream>

using namespace std;

struct element
{
    int rowNo;
    int colNo;
    int value;
};

class Sparse
{

public:
    int numberOfRows;
    int numberOfCols;
    int numberOfElements;
    element *e;

    Sparse(int m, int n, int num)
    {
        numberOfRows = m;
        numberOfCols = n;
        numberOfElements = num;
        e = new element[num];
    }

    ~Sparse()
    {
        delete e;
        e = nullptr;
    }

    void create()
    {
        cout << "\nEnter row no, column no (both in increasing order) and non-zero elements :\n\n";
        for(int i = 0; i < numberOfElements; i++){
            cin >> e[i].rowNo >> e[i].colNo >> e[i].value;
        }
        return;
    }

    void display()
    {
        int i, j, k = 0;
        for(i = 0; i < numberOfRows; i++){
            for(j = 0; j < numberOfCols; j++){
                cout.width(2);
                cout.setf(ios::adjustfield);
                if(i == e[k].rowNo-1 && j == e[k].colNo-1)
                    cout << e[k++].value << " ";
                else cout << 0 << " ";
            }
            cout << '\n';
        }
        return;
    }

};

Sparse addMatrices(Sparse s1, Sparse s2)
{
    Sparse sum(0, 0, 0);
    sum.numberOfRows = s1.numberOfRows;
    sum.numberOfCols = s1.numberOfCols;
    sum.e = new element[s1.numberOfElements+s2.numberOfElements];

    int i = 0, j = 0, k = 0;
    while(i < s1.numberOfElements && j < s2.numberOfElements){
        if(s1.e[i].rowNo < s2.e[j].rowNo){
            sum.e[k++] = s1.e[i++];
        }
        else if(s1.e[i].rowNo > s2.e[j].rowNo){
            sum.e[k++] = s2.e[j++];
        }
        else{
            if(s1.e[i].colNo < s2.e[j].colNo){
                sum.e[k++] = s1.e[i++];
            }
            else if(s1.e[i].colNo > s2.e[j].colNo){
                sum.e[k++] = s2.e[j++];
            }
            else{
                sum.e[k] = s1.e[i++];
                sum.e[k++].value += s2.e[j++].value;
            }
        }
    }

    while(i < s1.numberOfElements) sum.e[k++] = s1.e[i++];
    while(j < s2.numberOfElements) sum.e[k++] = s2.e[j++];
    sum.numberOfElements = k;
    return sum;
}

int main()
{
    int m, n, num;

    cout << "Enter dimensions of 1st sparse matrix : ";
    cin >> m >> n;
    cout << "Number of non-zero elements = ";
    cin >> num;
    Sparse s1(m, n, num);
    if(num > 0) s1.create();

    cout << "\nEnter dimensions of 2nd sparse matrix : ";
    cin >> m >> n;
    cout << "Number of non-zero elements = ";
    cin >> num;
    Sparse s2(m, n, num);
    if(num > 0) s2.create();

    cout << "\n\n1st sparse matrix :\n\n";
    s1.display();
    cout << "\n2nd sparse matrix :\n\n";
    s2.display();

    if(s1.numberOfRows != s2.numberOfRows && s1.numberOfCols != s2.numberOfCols){
        cout << "\nThe matrices are not addable\n";
    }
    else{
        Sparse sum = addMatrices(s1, s2);
        cout << "\nSum of the matrices :\n\n";
        sum.display();
    }
    return 0;
}
