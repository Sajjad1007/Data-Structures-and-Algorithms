// Some other binary operations of arrays are append(), compare(), copy() etc.

#include <iostream>

using namespace std;

struct Set
{
    int sz;
    int arr[20];

    void input()
    {
        cout << "\nNumber of elements : ";
        scanf("%d", &sz);
        cout << "Enter the elements in sorted order : ";
        for(int i = 0; i < sz; i++)
        {
            cin >> arr[i];
        }
        return;
    }

    void Insert()
    {
        int i = sz-1, val;
        cout << "Enter the element : ";
        cin >> val;

        while(i >= 0 && val < arr[i])
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = val;
        sz++;
        return;
    }

    void display()
    {
        for(int i = 0; i < sz; i++)
        {
            if(i == sz-1)
            {
                printf("%d}", arr[i]);
            }
            else
            {
                printf("%d, ", arr[i]);
            }
        }
        printf("\n");
        return;
    }
};

Set A = {{1, 3, 5, 7, 9}, 5};
Set B = {{1, 2, 3, 4, 5}, 5};

void Merge()
{
    int i = 0, j = 0, k = 0;
    Set C;

    while(i < A.sz && j < B.sz)
    {
        if(A.arr[i] < B.arr[j])
        {
            C.arr[k++] = A.arr[i++];
        }
        else
        {
            C.arr[k++] = B.arr[j++];
        }
    }

    while(i < A.sz)
    {
        C.arr[k++] = A.arr[i++];
    }
    while(j < B.sz)
    {
        C.arr[k++] = B.arr[j++];
    }

    C.sz = k;
    cout << "\nA merge B : {";
    C.display();
    return;
}

void concat()
{
    int i = 0, j = 0, k = 0;
    Set C;

    while(i < A.sz)
    {
        C.arr[k++] = A.arr[i++];
    }
    while(j < B.sz)
    {
        C.arr[k++] = B.arr[j++];
    }

    C.sz = k;
    cout << "\nA concat B : {";
    C.display();
    return;
}

// Union(), Intersection() and Difference() functions will work when the sets are in sorted order.
void Union()
{
    int i = 0, j = 0, k = 0;
    Set C;

    while(i < A.sz && j < B.sz)
    {
        if(A.arr[i] < B.arr[j])
        {
            C.arr[k++] = A.arr[i++];
        }
        else if(B.arr[j] < A.arr[i])
        {
            C.arr[k++] = B.arr[j++];
        }
        else
        {
            C.arr[k++] = A.arr[i++];
            j++;
        }
    }

    while(i < A.sz)
    {
        C.arr[k++] = A.arr[i++];
    }
    while(j < B.sz)
    {
        C.arr[k++] = B.arr[j++];
    }

    C.sz = k;
    cout << "\nA union B : {";
    C.display();
    return;
}

void intersect()
{
    int i = 0, j = 0, k = 0;
    Set C;

    while(i < A.sz && j < B.sz)
    {
        if(A.arr[i] == B.arr[j])
        {
            C.arr[k++] = A.arr[i++];
            j++;
        }
        else if(A.arr[i] < B.arr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    C.sz = k;
    cout << "\nA intersect B : {";
    C.display();
    return;
}

void difference()
{
    int i = 0, j = 0, k = 0;
    Set C;

    while(i < A.sz && j < B.sz)
    {
        if(A.arr[i] < B.arr[j])
        {
            C.arr[k++] = A.arr[i++];
        }
        else if(A.arr[i] > B.arr[j])
        {
            j++;
        }
        else
        {
            i++;
            j++;
        }
    }

    while(i < A.sz)
    {
        C.arr[k++] = A.arr[i++];
    }

    C.sz = k;
    cout << "\nA \\ B : {";
    C.display();
    return;
}

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Define sets\n";
    cout << "2. Insert\n";
    cout << "3. Display sets\n";
    cout << "4. A merge B\n";
    cout << "5. A concat B\n";
    cout << "6. A union B\n";
    cout << "7. A intersect B\n";
    cout << "8. A \\ B\n";
    cout << "9. Quit\n";
    return;
}

int main(void)
{
    int ch;
    char c;
    cout << "Set A : {";
    A.display();
    cout << "Set B : {";
    B.display();
    cout << "\n";

    while(true)
    {
        choice_list();
        printf("\nEnter your choice : ");
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter set name : ";
                cin >> c;
                c = toupper(c);

                switch(c)
                {
                    case 'A':
                        A.input();
                        break;

                    case 'B':
                        B.input();
                        break;

                    default:
                        cout << "\nInvalid set name\n";
                        break;
                }
                break;

            case 2:
                cout << "Enter set name : ";
                cin >> c;
                c = toupper(c);

                switch(c)
                {
                    case 'A':
                        A.Insert();
                        cout << "\nSet A : {";
                        A.display();
                        break;

                    case 'B':
                        B.Insert();
                        cout << "\nSet B : {";
                        B.display();
                        break;

                    default:
                        cout << "\nInvalid set name\n";
                        break;
                }
                break;

            case 3:
                cout << "\nSet A : {";
                A.display();
                cout << "Set B : {";
                B.display();
                break;

            case 4:
                Merge();
                break;

            case 5:
                concat();
                break;

            case 6:
                Union();
                break;

            case 7:
                intersect();
                break;

            case 8:
                difference();
                break;

            case 9:
                cout << "\nFee Amanillah\n";
                return 0;

            default:
                cout << "\nInvalid choice\n";
                break;
        }
        printf("\n");
    }
}

/*
Menu driven program
*/
