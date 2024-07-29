#include <iostream>

using namespace std;

class Stack
{
private:
    struct node
    {
        int val;
        node *next;

        node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    } *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        node *p = top;
        while(top)
        {
            top = top->next;
            delete p;
            p = top;
        }
        p = nullptr;
    }

    bool Empty()
    {
        return (top == nullptr);
    }

    void push(int val)
    {
        node *t = new node(val);
        t->next = top;
        top = t;
        return;
    }

    void pop()
    {
        if(Empty())
        {
            cout << "\nStack underflow\n";
            exit(1);
        }

        node *t = top;
        top = top->next;
        delete t;
        t = nullptr;
        return;
    }

    int Top()
    {
        return top->val;
    }

    void display()
    {
        if(Empty())
        {
            cout << "\nThe stack is empty.\n";
            return;
        }

        node *p = top;
        cout << "\nThe stack :";
        while(p)
        {
            cout  << " " << p->val;
            p = p->next;
        }
        cout << "\n";
        return;
    }
};

void choice_list()
{
    cout << "Menu\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Print the top element\n";
    cout << "4. Quit\n";
    return;
}

int main()
{
    int ch, val;
    Stack s;
    cout << "The stack has been initialized.\n\n";

    while(true)
    {
        choice_list();
        cout << "\nEnter your choice : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
                cout << "Enter the element : ";
                cin >> val;
                s.push(val);
                s.display();
                break;

            case 2:
                s.pop();
                s.display();
                break;

            case 3:
                if(s.Empty())
                {
                    cout << "\nThe stack is empty.\n";
                }
                else
                {
                    cout << "\nThe top element is " << s.Top() << ".\n";
                }
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
