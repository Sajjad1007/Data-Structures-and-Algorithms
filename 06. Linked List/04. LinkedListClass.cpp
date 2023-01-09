#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{

private:
    node *first;

public:
    LinkedList()
    {
        first = nullptr;
    }

    LinkedList(int arr[], int n)
    {
        node *t = nullptr;
        node *last = nullptr;

        if(n == 0) first = nullptr;
        else{
            first = new node(arr[0]);
            last = first;
        }

        for(int i = 1; i < n; i++){
            t = new node(arr[i]);
            last->next = t;
            last = t;
        }
    }

    ~LinkedList()
    {
        node *p = first;
        while(first){
            first = first->next;
            delete p;
            p = first;
        }
        p = nullptr;
    }

    node *getFirst()
    {
        return first;
    }

    bool isLoop()
    {
        node *p = first;
        node *q = p;

        do{
            p = p->next;
            q = q->next;
            q = (q != nullptr) ? q->next : nullptr;
        } while(p && q);

        return (p == q) ? true : false;
    }

    int Count()
    {
        int cnt = 0;
        node *p = first;

        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    void Insert(int pos, int val)
    {
        if(pos < 1 || pos > Count() + 1) return;
        node *p = first;
        node *t = new node(val);

        if(pos == 1){
            t->next = first;
            first = t;
        }
        else if(pos > 0){
            for(int i = 1; i < pos - 1 && p != nullptr; i++){
                p = p->next;
            }
            t->next = p->next;
            p->next = t;
        }
        return;
    }

    void Delete(int pos)
    {
        node *p = first;
        node *q = nullptr;

        if(pos < 1 || pos > Count()) return;
        else if(pos == 1){
            p = first;
            first = first->next;
            cout << "Deleted value : " << p->data << '\n';
            delete p;
            p = nullptr;
        }
        else{
            for(int i = 1; i < pos; i++){
                q = p;
                p = p->next;
            }

            q->next = p->next;
            cout << "Deleted value : " << p->data << '\n';
            delete p;
            p = nullptr;
        }
        return;
    }

    void display()
    {
        node *p = first;
        while(p){
            cout  << " " << p->data;
            p = p->next;
        }
        return;
    }

    void reverseDisplay(node *p)
    {
        if(!p) return;
        reverseDisplay(p->next);
        cout << " " << p->data;
        return;
    }

};

int main()
{
    int pos, val, key;
    int arr[] = {3, 8, 7, 2, 5};

    LinkedList List(arr, 5);
    cout << "The linked list :";
    List.display();

    if(List.isLoop()) cout << " (a loop)" << '\n';
    else cout << " (not a loop)" << '\n';

    cout << "The reversed linked list :";
    List.reverseDisplay(List.getFirst());
    cout << "\nNumber of nodes = " << List.Count() << '\n';

    cout << "\nEnter the position (1 to 6) and value to insert : ";
    cin >> pos >> val;
    List.Insert(pos, val);
    cout << "The linked list :";
    List.display();
    cout << "\n\nEnter the position (1 to 6) to delete : ";
    cin >> pos;
    List.Delete(pos);
    cout << "The linked list :";
    List.display();
    cout << '\n';
    return 0;
}

/*
The linked list : 3 8 7 2 5 (not a loop)
The reversed linked list : 5 2 7 8 3
Number of nodes = 5

Enter the position (1 to 6) and value to insert : 5 6
The linked list : 3 8 7 2 6 5

Enter the position (1 to 6) to delete : 3
Deleted value : 7
The linked list : 3 8 2 6 5
*/
