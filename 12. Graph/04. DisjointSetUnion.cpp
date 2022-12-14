//Disjoint Set is used to know whether or not two elements belong to same set.

#include <iostream>
#include <cmath>

#define MAX 101

using namespace std;

int parent[MAX];

void makeSet(int u)
{
    parent[u] = u;
    return;
}

int Find(int u)
{
    if(parent[u] == u) return u;
    parent[u] = Find(parent[u]); //path compression happened
    return parent[u];
}

void Union(int u, int v)
{

    int p = Find(u);
    int q = Find(v);

    if(q != 0) parent[q] = p;
    else parent[v] = p;
    return;
}

bool isFriend(int u, int v)
{
    int p = Find(u);
    int q = Find(v);
    return (p == q);
}

void printSet(int u)
{
    int i, p;
    p = Find(u);

    for(i = 1; i <= MAX; i++){
        if(p == Find(i)) cout << " " << i;
    }

    cout << '\n';
    return;
}

void printChoiceList()
{
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
    int c, n, p, i, x, y;

    cout << "Disjoint Set Operations\n\n";
    while(true){
        printChoiceList();
        cout << "\nEnter your choice : ";
        cin >> c;

        switch(c)
        {
            case 1:
                cout << "\nNumber of elements : ";
                cin >> n;
                cout << "Enter the elements : ";
                cin >> p;
                makeSet(p);

                for(i = 2; i <= n; i++){
                    cin >> x;
                    Union(p, x);
                }
                break;

            case 2:
                cout << "\nEnter the element : ";
                cin >> x;
                p = Find(x);

                if(p != 0)
                    cout << "The representative of the set where " << x << " belongs is " << Find(x) << '\n';
                else cout << x << " does not have any representative\n";
                break;

            case 3:
                cout << "\nEnter an element of set 1 : ";
                cin >> x;
                cout << "Enter an element of set 2 : ";
                cin >> y;
                Union(x, y);
                cout << "\nUnion of the sets :";
                printSet(x);
                break;

            case 4:
                cout << "\nEnter the elements to be checked : ";
                cin >> x >> y;

                if(isFriend(x, y)) cout << x << " and " << y << " are friends\n";
                else cout << x << " and " << y << " are not friends\n";
                break;

            case 5:
                cout << "\nEnter an element of the set : ";
                cin >> x;
                p = Find(x);

                if(p != 0){
                    cout << "The set :";
                    printSet(x);
                }
                else cout << x << " does not belong to any set\n";
                break;

            case 6:
                cout << "\nFee Amanillah\n";
                return 0;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
        cout << '\n';
    }
}
