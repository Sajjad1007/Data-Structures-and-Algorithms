/*
Notes:

1. Hashing is a searching technique whose time complexity is O(1).
2. Loading Factor, lf = number of elements/size of the hash table.
3. In open hashing, extra spaces will be consumed if needed.
4. Chaining is a method of open hashing technique.
5. In chaining method, the size of the hash table should be anything.
*/

#include <iostream>

#define sz 10

using namespace std;

struct node
{
    int val;
    node *next;

    node(int val)
    {
        this->val = val;
        this->next = nullptr;
    }
};

node *hash_table[sz];         // 'hash_table' is a pointer to an array of 10 nodes.

int Hash(int key)
{
    return key%sz;
}

void Insert(int val)
{
    int indx = Hash(val);
    node *p = hash_table[indx], *q = nullptr;
    node *t = new node(val);

    if(hash_table[indx] == nullptr)
    {
        hash_table[indx] = t;
    }
    else
    {
        while(p != nullptr && p->val < val)
        {
            q = p;
            p = p->next;
        }

        if(p == hash_table[indx])
        {
            t->next = hash_table[indx];
            hash_table[indx] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
    return;
}

bool Search(int key)
{
    int indx = Hash(key);
    node *p = hash_table[indx];

    while(p)
    {
        if(key == p->val)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void print(node *p)
{
    while(p)
    {
        cout << " " << p->val;
        p = p->next;
    }
    return;
}

int main()
{
    int i, n, val;

    cout << "Number of elements : ";
    cin >> n;
    cout << "Enter the elements : ";
    for(i = 0; i < n; i++)
    {
        cin >> val;
        Insert(val);
    }

    cout << "\nThe hash table\n";
    for(i = 0; i < sz; i++)
    {
        cout << "\nindex " << i << " :";
        print(hash_table[i]);
    }

    cout << "\n\nEnter an element to be searched : ";
    cin >> val;
    if(Search(val))
    {
        cout << "\n" << val << " is found\n";
    }
    else
    {
        cout << "\n" << val << " is not found\n";
    }
    return 0;
}

/*
Number of elements : 10
Enter the elements : 4 3 12 9 33 25 7 19 6 20

The hash table

index 0 : 20
index 1 :
index 2 : 12
index 3 : 3 33
index 4 : 4
index 5 : 25
index 6 : 6
index 7 : 7
index 8 :
index 9 : 9 19

Enter an element to be searched : 33

33 is found
*/
