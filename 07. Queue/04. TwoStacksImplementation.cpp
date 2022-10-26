#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

class Stack
{

private:
    node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    ~Stack()
    {
        node *p = top;
        while(top){
            top = top->next;
            delete p;
            p = top;
        }
        p = nullptr;
    }

    node *getTop()
    {
        return top;
    }

    int getTopElement()
    {
        return top->data;
    }

    bool isEmpty()
    {
        if(top == nullptr) return true;
        else return false;
    }

    void push(int data)
    {
        node *t = new node;
        t->data = data;
        t->next = top;
        top = t;
        return;
    }

    int pop()
    {
        int data = top->data;
        node *t = top;
        top = top->next;

        delete t;
        t = nullptr;
        return data;
    }

} s1, s2;

void printChoiceList()
{
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Print the front element\n";
    cout << "4. Quit\n";
    return;
}

void printStack2(struct node *p)
{
    cout << "The queue :";
    while(p){
        cout << " " << p->data;
        p = p->next;
    }
    return;
}

void printStack1(struct node *p)
{
    if(p == nullptr) return;
    printStack1(p->next);
    cout << " " << p->data;
    return;
}

int main()
{
    int choice, data, pos;
    cout << "The queue has been initialized\n\n";

    while(true){
        printChoiceList();
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter the element to be enqueued : ";
                cin >> data;
                s1.push(data);
                cout << '\n' << data << " is enqueued successfully\n";
                printStack2(s2.getTop());
                printStack1(s1.getTop());
                cout << '\n';
                break;
            case 2:
                if(!s2.isEmpty()) cout << "\nDeleted element is " << s2.pop() << '\n';
                else if(!s1.isEmpty()){
                    while(!s1.isEmpty()) s2.push(s1.pop());
                    cout << "\nDeleted element is " << s2.pop();
                }

                if(s1.isEmpty() && s2.isEmpty()) cout << "\nThe queue is empty\n";
                else{
                    printStack2(s2.getTop());
                    printStack1(s1.getTop());
                    cout << '\n';
                }
                break;
            case 3:
                if(!s2.isEmpty()){
                    cout << "\nThe front element is " << s2.getTopElement() << '\n';
                }
                else if(!s1.isEmpty()){
                    while(!s1.isEmpty()) s2.push(s1.pop());
                    cout << "\nThe front element is " << s2.getTopElement() << '\n';
                }
                else cout << "\nThe queue is empty\n";
                break;
            case 4:
                cout << "\nFee Amanillah\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
        cout << '\n';
    }
}
