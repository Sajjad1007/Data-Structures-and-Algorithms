#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
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
        node *last = nullptr;
        first = new node;
        if(n == 0) first = nullptr;
        else{
            first->data = arr[0];
            first->next = nullptr;
            last = first;
        }

        node *t = nullptr;
        for(int i = 1; i < n; i++){
            t = new node;
            t->data = arr[i];
            t->next = nullptr;
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
        node *p = first;
        int cnt = 0;
        while(p){
            cnt++;
            p = p->next;
        }
        return cnt;
    }

    void Insert(int pos, int val)
    {
        if(pos < 1 || pos > Count()+1) return;
        node *p = first;
        node *t = new node;
        t->data = val;
        if(pos == 1){
            t->next = first;
            first = t;
        }
        else if(pos > 0){
            for(int i = 1; i < pos-1 && p != nullptr; i++){
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
            cout << "Deleted value : " << p->data << endl;
            delete p;
        }
        else{
            for(int i = 1; i < pos; i++){
                q = p;
                p = p->next;
            }
            q->next = p->next;
            cout << "Deleted value : " << p->data << endl;
            delete p;
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
        if(p == nullptr) return;
        reverseDisplay(p->next);
        printf(" %d", p->data);
        return;
    }

};

int main()
{
    int key, arr[] = {3, 8, 7, 10, 5};
    int pos, val;
    LinkedList List(arr, 5);
    cout << "The linked list :";
    List.display();
    if(List.isLoop()) cout << " (a loop)" << endl;
    else cout << " (not a loop)" << endl;
    cout << "The reversed linked list :";
    List.reverseDisplay(List.getFirst());
    cout << "\nNumber of nodes = " << List.Count() << endl;

    cout << "\nEnter the position(1 to 6) and value to insert : ";
    cin >> pos >> val;
    List.Insert(pos, val);
    cout << "The linked list :";
    List.display();
    cout << "\n\nEnter the position(1 to 6) to delete : ";
    cin >> pos;
    List.Delete(pos);
    cout << "The linked list :";
    List.display();
    cout << endl;
    return 0;
}
