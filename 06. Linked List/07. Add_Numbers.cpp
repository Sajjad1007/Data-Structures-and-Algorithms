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

struct number
{
    node *head = nullptr;
    node *tail = nullptr;

    void add_node(int val)
    {
        node *t = new node(val);

        if(this->tail == nullptr)
        {
            tail = head = t;
        }
        else
        {
            tail->next = t;
            tail = t;
        }
        return;
    }

    void init(int n)
    {
        while(n)
        {
            add_node(n%10);
            n /= 10;
        }
        return;
    }

    void display(node *p)
    {
        if(p == nullptr)
        {
            return;
        }
        display(p->next);
        cout << p->val;
        return;
    }

    void display()
    {
        display(this->head);
        cout << "\n";
        return;
    }
};

number add_number(number num1, number num2)
{
    int sum = 0;
    number num3;
    node *p1 = num1.head;
    node *p2 = num2.head;

    while(p1 || p2)
    {
        if(p1)
        {
            sum += p1->val;
            p1 = p1->next;
        }
        if(p2)
        {
            sum += p2->val;
            p2 = p2->next;
        }
        num3.add_node(sum%10);
        sum /= 10;
    }

    if(sum != 0)
    {
        num3.add_node(sum);
    }
    return num3;
}

int main()
{
    int n1, n2;
    number num1, num2;
    cout << "Enter two positive numbers = ";
    cin >> n1 >> n2;
    num1.init(n1);
    num2.init(n2);

    number num3 = add_number(num1, num2);
    cout << "\nThe sum of two numbers = ";
    num3.display();
    return 0;
}

/*
Enter two positive numbers = 14 35

The sum of two numbers = 49
*/
