#include <iostream>

#define MAX 100

using namespace std;

class Queue
{
private:
    int top1 = -1;
    int top2 = -1;
    int stack_arr1[MAX];
    int stack_arr2[MAX];

public:
    bool Empty()
    {
        return (top1 == -1 && top2 == -1);
    }

    void push(int val)
    {
        if((top1+top2) == MAX-2)
        {
            cout << "Queue overflow\n";
            exit(1);
        }
        stack_arr1[++top1] = val;
        return;
    }

    void pop()
    {
        if(top2 == -1)
        {
            if(top1 == -1)
            {
                cout << "\nQueue underflow\n";
                exit(1);
            }

            while(top1 != -1)
            {
                stack_arr2[++top2] = stack_arr1[top1--];
            }
        }
        stack_arr2[top2--];
        return;
    }

    int Front()
    {
        if(top2 == -1)
        {
            if(top1 == -1)
            {
                cout << "\nQueue underflow\n";
                exit(1);
            }
            else
            {
                return stack_arr1[0];
            }
        }
        else
        {
            return stack_arr2[top2];
        }
    }

    void display()
    {
        if(top1 == -1 && top2 == -1)
        {
            cout << "\nThe queue is empty.\n";
            return;
        }

        cout << "\nThe queue :";
        for(int i = top2; i >= 0; --i)
        {
            cout << " " << stack_arr2[i];
        }
        for(int i = 0; i <= top1; ++i)
        {
            cout << " " << stack_arr1[i];
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
    cout << "3. Print the front element\n";
    cout << "4. Quit\n";
    return;
}

int main()
{
    int ch, val;
    Queue q;
    cout << "The queue has been initialized.\n\n";

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
                q.push(val);
                q.display();
                break;

            case 2:
                q.pop();
                q.display();
                break;

            case 3:
                if(q.Empty())
                {
                    cout << "\nThe queue is empty.\n";
                }
                else
                {
                    cout << "\nThe front element is " << q.Front() << ".\n";
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
