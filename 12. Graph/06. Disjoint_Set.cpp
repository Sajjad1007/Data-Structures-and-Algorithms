// Disjoint Set data structure is used to know whether two elements belong to same set or not.

#include <iostream>
#include <vector>

#define MAX 101

using namespace std;

int parent[MAX];

int Find(int u)
{
    if(parent[u] == u)
    {
        return u;
    }
    parent[u] = Find(parent[u]);             // Path compression
    return parent[u];
}

void Union(int u, int v)
{
    int p = Find(u);
    int q = Find(v);

    if(p == 0)
    {
        parent[u] = q;
    }
    else if(q == 0)
    {
        parent[v] = p;
    }
    else
    {
        parent[q] = p;
    }
    return;
}

bool Friend(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    return (p == q);
}

void print_set(int u)
{
    int i, p;
    p = Find(u);

    for(i = 1; i <= MAX; i++)
    {
        if(p == Find(i))
        {
            cout << " " << i;
        }
    }
    cout << "\n";
    return;
}

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Create set\n";
    cout << "2. Find\n";
    cout << "3. Union\n";
    cout << "4. Check friend\n";
    cout << "5. Print set\n";
    cout << "6. Quit\n";
    return;
}

int main()
{
    int ch, i, n, p, x, y;

    cout << "Disjoint Set Operations\n\n";
    while(true)
    {
        choice_list();
        cout << "\nEnter your choice  : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Number of elements : ";
                cin >> n;
                cout << "Enter the elements : ";
                cin >> p;
                parent[p] = p;

                for(i = 2; i <= n; i++)
                {
                    cin >> x;
                    Union(p, x);
                }
                break;

            case 2:
                cout << "Enter the element  : ";
                cin >> x;
                p = Find(x);

                if(p != 0)
                {
                    cout << "\nThe parent of " << x << " is " << Find(x) << "\n";
                }
                else
                {
                    cout << "\n" << x << " does not have any parent\n";
                }
                break;

            case 3:
                cout << "Enter an element of 1st set : ";
                cin >> x;
                cout << "Enter an element of 2nd set : ";
                cin >> y;

                if(parent[x] == 0 && parent[y] == 0)
                {
                    parent[x] = parent[y] = x;
                }
                else
                {
                    Union(x, y);
                }

                cout << "\nUnion of the sets :";
                print_set(x);
                break;

            case 4:
                cout << "Enter two elements : ";
                cin >> x >> y;

                if(Friend(x, y))
                {
                    cout << "\n" << x << " and " << y << " are friends\n";
                }
                else
                {
                    cout << "\n" << x << " and " << y << " are not friends\n";
                }
                break;

            case 5:
                cout << "Enter an element of the set : ";
                cin >> x;
                p = Find(x);

                if(p != 0)
                {
                    cout << "\nThe set :";
                    print_set(x);
                }
                else
                {
                    cout << x << " does not belong to any set\n";
                }
                break;

            case 6:
                cout << "\nFee Amanillah\n";
                return 0;

            default:
                cout << "\nInvalid choice\n";
                break;
        }
        cout << "\n";
    }
}

/*
Menu driven program
*/
