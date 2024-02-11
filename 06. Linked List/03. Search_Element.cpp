#include <iostream>

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

node *head = nullptr;
node *tail = nullptr;

void input()
{
    int i, val, list_size;
    cout << "Number of elements : ";
    cin >> list_size;
    cout << "Enter the elements : ";
    cin >> val;
    head = tail = new node(val);

    for(i = 2; i <= list_size; i++)
    {
        cin >> val;
        node *t = new node(val);
        tail->next = t;
        tail = t;
    }
    cout << "\n";
    return;
}

// We can improve this linear search by using 'Transposition' or 'Move-to-head' technique just like arrays.
int linear_search(int key)
{
    int pos = 0;
    node *p = head;

    do
    {
        pos++;
        if(key == p->val)
        {
            return pos;
        }
        p = p->next;
    } while(p);
    return -1;
}

bool loop()
{
    node *p = head;
    node *q = p;

    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : nullptr;
    } while(p and q);

    return (p == q) ? true : false;
}

bool sorted()
{
    node *p = head;
    int val = p->val;

    while(p)
    {
        if(val > p->val)
        {
            return false;
        }
        else
        {
            val = p->val;
            p = p->next;
        }
    }
    return true;
}

void insert_sorted()
{
    int val;
    node *p = head;
    cout << "Enter an element : ";
    cin >> val;
    node *t = new node(val);

    while(p->next && (p->next->val < val))
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
    return;
}

void middle_element()
{
    node *p = head;
    node *q = head;

    while(q)
    {
        q = q->next;
        if(q)
        {
            q = q->next;
        }
        if(q)
        {
            p = p->next;
        }
    }

    cout << "\nThe middle element is " << p->val << "\n";
    return;
}

void remove_duplicates()
{
    node *p = head;
    node *q = head->next;

    while(q)
    {
        if(q->val != p->val)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
    return;
}

void display()
{
    node *p = head;
    cout << "\nThe linked list :";
    while(p)
    {
        cout  << " " << p->val;
        p = p->next;
    }
    cout << "\n";
    return;
}

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Search\n";
    cout << "2. Check loop\n";
    cout << "3. Insert sorted\n";
    cout << "4. Middle element\n";
    cout << "5. Remove duplicates\n";
    cout << "6. Quit\n";
    return;
}

int main()
{
    int ch, pos, key;
    input();

    while(true)
    {
        choice_list();
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter an element for searching : ";
                cin >> key;
                pos = linear_search(key);

                if(pos >= 1)
                {
                    printf("\n%d is at position %d\n", key, pos);
                }
                else
                {
                    printf("\n%d is not found\n", key);
                }
                break;

            case 2:
                if(loop())
                {
                    cout << "\nThe linked list has a loop\n";
                }
                else
                {
                    cout << "\nThe linked list does not have a loop\n";
                }
                break;

            case 3:
                if(sorted())
                {
                    insert_sorted();
                    display();
                }
                else
                {
                    cout << "\nThe linked list is not sorted\n";
                }
                break;

            case 4:
                middle_element();
                break;

            case 5:
                if(sorted())
                {
                    remove_duplicates();
                    display();
                }
                else
                {
                    cout << "\nThe linked list is not sorted\n";
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
