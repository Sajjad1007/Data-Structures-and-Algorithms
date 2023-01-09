#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
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

    bool isEmpty()
    {
        if(top == nullptr) return true;
        else return false;
    }

    bool isFull()
    {
        node *t = new node(0);
        if(t == nullptr) return true;
        else{
            delete t;
            t = nullptr;
            return false;
        }
    }

    int Count()
    {
        node *p = top;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    void push(int data)
    {
        node *t = new node(data);
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

    int peek(int pos)
    {
        node *p = top;
        for(int i = 1; i < pos; i++) p = p->next;
        return p->data;
    }

    int getTopElement()
    {
        return top->data;
    }

    void display()
    {
        node *p = top;
        cout << "The stack :";
        while(p){
            cout  << " " << p->data;
            p = p->next;
        }
        cout << '\n';
        return;
    }

};

void printChoiceList()
{
    cout << "Menu\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Print the topmost element\n";
    cout << "4. Print any element\n";
    cout << "5. Quit\n";
    return;
}

int main()
{
    int choice, data, pos;
    Stack st;
    cout << "The stack has been initialized\n\n";

    while(true){
        printChoiceList();
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(!st.isFull()){
                    cout << "Enter the element to be pushed : ";
                    cin >> data;
                    st.push(data);
                    cout << '\n' << data << " has been pushed\n";
                    st.display();
                }
                else cout << "\nStack overflow\n";
                break;

            case 2:
                if(!st.isEmpty()){
                    cout << '\n' << st.pop() << " has been popped\n";
                    if(!st.isEmpty()) st.display();
                    else cout << "The stack is empty\n";
                }
                else cout << "\nThe stack is empty\n";
                break;

            case 3:
                if(!st.isEmpty()){
                    cout << "\nThe topmost element is " << st.getTopElement() << '\n';
                }
                else cout << "\nThe stack is empty\n";
                break;

            case 4:
                if(!st.isEmpty()){
                    cout << "Enter the position : ";
                    cin >> pos;
                    if(pos > st.Count() || pos < 1) cout << "\nInvalid position\n";
                    else cout << st.peek(pos) << " is at position " << pos << '\n';
                }
                else cout << "\nThe stack is empty\n";
                break;

            case 5:
                cout << "\nFee Amanillah\n";
                return 0;

            default:
                cout << "\nInvalid choice\n";
                break;
        }
        cout << '\n';
    }
}

/*
Menu driven program
*/
