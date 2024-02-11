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

int list_size;
node *head, *tail;

void input()
{
    int i, val;
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
    return;
}

void Insert()
{
    int i, pos, val;
    cout << "Enter the position : ";
    cin >> pos;

    if(pos >= 1 && pos <= list_size+1)
    {
        cout << "Enter an element : ";
        cin >> val;
        node *p = head;
        node *t = new node(val);

        if(pos == 1)
        {
            t->next = head;
            head = t;
        }
        else
        {
            for(i = 1; i < pos-1; i++)
            {
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
        list_size++;
    }
    return;
}

void Delete()
{
    int i, pos;
    cout << "Enter the position : ";
    cin >> pos;

    if(pos >= 1 && pos <= list_size)
    {
        if(pos == 1)
        {
            node *p = head;
            head = head->next;
            delete p;
            p = nullptr;
        }
        else
        {
            node *p = head, *q;
            for(i = 1; i < pos; i++)
            {
                q = p;
                p = p->next;
            }
            q->next = p->next;
            delete p;
            p = nullptr;
        }
        list_size--;
    }
    return;
}

void update()
{
    int i, pos, val;
    cout << "Enter the position : ";
    cin >> pos;

    if(pos >= 1 && pos <= list_size)
    {
        cout << "Enter an element : ";
        cin >> val;
        node *p = head;
        for(i = 2; i <= pos; i++)
        {
            p = p->next;
        }
        p->val = val;
    }
    return;
}

void Reverse()
{
    node *p = head, *r;
    node *q = nullptr;

    while(p != nullptr)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
    return;
}

/**
void Reverse(node *p, node *q)
{
    if(q == nullptr)
    {
        head = p;
    }
    else
    {
        Reverse(q, q->next);
        q->next = p;
    }
    return;
}
**/

void left_rotation()
{
    int i, n;
    node *p = head, *q;
    cout << "Number of elements to rotate : ";
    cin >> n;
    n %= list_size;

    if(n == 0)
    {
        return;
    }

    for(i = 1; i < list_size; i++)
    {
        if(i == n)
        {
            q = p;
            p = p->next;
        }
        else
        {
            p = p->next;
        }
    }

    p->next = head;
    head = q->next;
    q->next = nullptr;
    return;
}

void max_min()
{
    int Max = head->val;
    node *p = head->next;

    while(p != nullptr)
    {
        if(Max < p->val)
        {
            Max = p->val;
        }
        p = p->next;
    }

    int Min = head->val;
    p = head->next;

    while(p != nullptr)
    {
        if(Min > p->val)
        {
            Min = p->val;
        }
        p = p->next;
    }

    cout << "\nMaximum element = " << Max << "\n";
    cout << "Minimum element = " << Min << "\n";
    return;
}

void sum_average()
{
    int sum = 0;
    float avg;
    node *p = head;

    while(p != nullptr)
    {
        sum += p->val;
        p = p->next;
    }

    avg = (float)sum/list_size;
    cout << "\nSum = " << sum << "\n";
    cout << "Average = " << avg << "\n";
    return;
}

void display()
{
    node *p = head;
    cout << "\nThe linked list :";
    while(p != nullptr)
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
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Update\n";
    cout << "4. Reverse\n";
    cout << "5. Left rotation\n";
    cout << "6. Maximum and minimum\n";
    cout << "7. Sum and average\n";
    cout << "8. Quit\n";
    return;
}

int main()
{
    int ch;
    input();
    cout << "\nThe singly linked list has been initialized\n\n";

    while(true)
    {
        choice_list();
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                Insert();
                display();
                break;

            case 2:
                Delete();
                display();
                break;

            case 3:
                update();
                display();
                break;

            case 4:
                Reverse();
                ///Reverse(nullptr, head);
                display();
                break;

            case 5:
                left_rotation();
                display();
                break;

            case 6:
                max_min();
                break;

            case 7:
                sum_average();
                break;

            case 8:
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
