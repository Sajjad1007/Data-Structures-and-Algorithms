#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

class Queue
{

private:
    node *Front;
    node *Rear;

public:
    Queue()
    {
        Front = nullptr;
        Rear = nullptr;
    }

    ~Queue()
    {
        node *p = Front;
        while(Front){
            Front = Front->next;
            delete p;
            p = Front;
        }
        p = nullptr;
    }

    node *getFront()
    {
        return Front;
    }

    node *getRear()
    {
        return Rear;
    }

    bool isEmpty()
    {
        if(Front == nullptr) return true;
        else return false;
    }

    bool isFull()
    {
        node *t = new node;
        if(t == nullptr) return true;
        else{
            delete t;
            t = nullptr;
            return false;
        }
    }

    int Count()
    {
        node *p = Front;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    void enqueue(int data)
    {
        node *t = new node;
        t->data = data;
        t->next = nullptr;
        if(Front == nullptr) Front = t;
        else Rear->next = t;
        Rear = t;
        return;
    }

    int dequeue()
    {
        int data = Front->data;
        node *t = Front;
        Front = Front->next;

        delete t;
        t = nullptr;
        return data;
    }

    int peek(int pos)
    {
        node *p = Front;
        for(int i = 1; i < pos; i++) p = p->next;
        return p->data;
    }

    int getFrontElement()
    {
        return Front->data;
    }

    void display()
    {
        node *p = Front;
        cout << "The queue :";
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
    cout << "1. Enqueue\n";
    cout << "2. Dequeue\n";
    cout << "3. Print the front element\n";
    cout << "4. Print any element\n";
    cout << "5. Quit\n";
    return;
}

int main()
{
    int choice, data, pos;
    Queue q;
    cout << "The queue has been initialized\n\n";

    while(true){
        printChoiceList();
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(!q.isFull()){
                    cout << "Enter the element to be enqueued : ";
                    cin >> data;
                    q.enqueue(data);
                    cout << '\n' << data << " is enqueued successfully\n";
                    q.display();
                }
                else cout << "\nQueue overflow\n";
                break;
            case 2:
                if(!q.isEmpty()){
                    cout << "\nDeleted element is " << q.dequeue() << '\n';
                    if(!q.isEmpty()) q.display();
                    else cout << "The queue is empty\n";
                }
                else cout << "\nThe queue is empty\n";
                break;
            case 3:
                if(!q.isEmpty()){
                    cout << "\nThe front element is " << q.getFrontElement() << '\n';
                }
                else cout << "\nThe queue is empty\n";
                break;
            case 4:
                if(!q.isEmpty()){
                    cout << "Enter the position : ";
                    cin >> pos;
                    if(pos > q.Count() || pos < 1) cout << "\nInvalid position\n";
                    else{
                        cout << "\nThe element at position " << pos << " is " << q.peek(pos) << '\n';
                    }
                }
                else cout << "\nThe queue is empty\n";
                break;
            case 5:
                cout << "\nFee Amanillah\n";
                return 0;
            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;
        }
        cout << '\n';
    }
}
