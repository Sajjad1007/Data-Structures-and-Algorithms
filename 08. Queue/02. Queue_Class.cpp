#include <iostream>

using namespace std;

class Queue
{
private:
    struct node
    {
        int val;
        struct node *next;

        node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    } *frnt, *rear;

public:
    Queue()
    {
        frnt = nullptr;
        rear = nullptr;
    }

    ~Queue()
    {
        node *p = frnt;
        while(frnt)
        {
            frnt = frnt->next;
            delete p;
            p = frnt;
        }
        p = nullptr;
    }

    bool Empty()
    {
        if(frnt == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push_Front(int val)
    {
        node *t = new node(val);

        if(frnt == nullptr)
        {
            rear = t;
        }
        else{
            t->next = frnt;
        }
        frnt = t;
        return;
    }

    void push_Back(int val)
    {
        node *t = new node(val);

        if(frnt == nullptr)
        {
            frnt = t;
        }
        else
        {
            rear->next = t;
        }
        rear = t;
        return;
    }

    void pop_Front()
    {
        if(Empty())
        {
            cout << "\nQueue underflow\n";
            exit(1);
        }

        node *t = frnt;
        frnt = frnt->next;
        delete t;
        t = nullptr;
        return;
    }

    void pop_Back()
    {
        if(Empty())
        {
            cout << "\nQueue underflow\n";
            exit(1);
        }

        else if(!frnt->next)
        {                // One element is left there in the queue.
            pop_Front();
            rear = nullptr;
            return;
        }

        rear = frnt;
        node *t = frnt->next;

        while(t->next)
        {
            rear = t;
            t = t->next;
        }
        delete t;
        rear->next = t = nullptr;
        return;
    }

    int Front()
    {
        return frnt->val;
    }

    int Rear()
    {
        return rear->val;
    }

    void display()
    {
        if(Empty())
        {
            cout << "\nThe queue is empty\n";
            return;
        }

        node *p = frnt;
        cout << "\nThe queue :";

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
    cout << "1. Push at front\n";
    cout << "2. Push at rear\n";
    cout << "3. Pop from front\n";
    cout << "4. Pop from rear\n";
    cout << "5. Print the front element\n";
    cout << "6. Print the rear element\n";
    cout << "7. Quit\n";
    return;
}

int main()
{
    int ch, val;
    Queue q;
    cout << "The queue has been initialized\n\n";

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
                q.push_Front(val);
                q.display();
                break;

            case 2:
                cout << "Enter the element : ";
                cin >> val;
                q.push_Back(val);
                q.display();
                break;

            case 3:
                q.pop_Front();
                q.display();
                break;

            case 4:
                q.pop_Back();
                q.display();
                break;

            case 5:
                if(q.Empty())
                {
                    cout << "\nThe queue is empty\n";
                }
                else
                {
                    cout << "\nThe front element is " << q.Front() << "\n";
                }
                break;

            case 6:
                if(q.Empty())
                {
                    cout << "\nThe queue is empty\n";
                }
                else
                {
                    cout << "\nThe rear element is " << q.Rear() << "\n";
                }
                break;

            case 7:
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
