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
    int n;
    node *head;
    node *tail;

    void add_node(int val)
    {
        node *t = new node(val);
        if(!tail){
            tail =  t;
        }
        else{
            tail->next = t;
            tail = t;
        }
        return;
    }

    void init()
    {
        head = new node(n % 10);
        tail = head;
        n /= 10;

        while(n){
            add_node(n % 10);
            n /= 10;
        }
        return;
    }

    void push_node(int val)
    {
        node *t = new node(val);
        t->next = head;
        head = t;
        return;
    }

    void display()
    {
        node *p = head;
        while(p){
            cout << p->val;
            p = p->next;
        }
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

    while(p1 || p2){
        if(p1){
            sum += p1->val;
            p1 = p1->next;
        }
        if(p2){
            sum += p2->val;
            p2 = p2->next;
        }
        num3.push_node(sum % 10);
        sum /= 10;
    }

    if(sum != 0){
        num3.push_node(sum);
    }
    return num3;
}

int main()
{
    number num1, num2;
    cout << "Enter two positive numbers = ";
    cin >> num1.n >> num2.n;
    num1.init();
    num2.init();

    number num3 = add_number(num1, num2);
    cout << "\nThe sum of two numbers = ";
    num3.display();
    return 0;
}

/*
Enter two positive numbers = 14 35

The sum of two numbers = 49
*/
