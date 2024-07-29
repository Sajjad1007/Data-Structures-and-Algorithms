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
    tail->next = head;

    for(i = 2; i <= list_size; i++)
    {
        cin >> val;
        node *t = new node(val);
        tail->next = t;
        tail = t;
        tail->next = head;
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
            tail->next = head;
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
            tail->next = head;
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

            if(q->next == head)
            {
                tail = q;
            }
        }
        list_size--;
    }
    return;
}

void Reverse()
{
    node *p = head, *r;
    node *q = tail;

    do
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    } while(p != head);

    head = q;
    tail = p;
    return;
}

void display()
{
    node *p = head;
    cout << "\nThe linked list :";
    do
    {
        cout << " " << p->val;
        p = p->next;
    } while(p != head);
    cout << "\n";
    return;
}

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Reverse\n";
    cout << "4. Quit\n";
    return;
}

int main()
{
    int ch;
    input();
    cout << "\nThe circular linked list has been initialized.\n\n";

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
                Reverse();
                display();
                break;

            case 4:
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
