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

struct Set
{
    node *head;
    node *tail;

    Set(int arr[], int n)
    {
        if(n == 0){
            head = nullptr;
        }
        else{
            head = new node(arr[0]);
            tail = head;
        }

        for(int i = 1; i < n; i++){
            node *t = new node(arr[i]);
            tail->next = t;
            tail = t;
        }
        return;
    }

    void display(node *p)
    {
        if(!p){
            printf("\n");
            return;
        }
        else if(p->next == nullptr){
            printf("%d}", p->val);
        }
        else{
            printf("%d, ", p->val);
        }

        display(p->next);
        return;
    }
};

int arr1[] = {1, 3, 5, 7, 9};
int arr2[] = {1, 2, 3, 4, 5};

Set A(arr1, 5);
Set B(arr2, 5);

void Merge()
{
    node *p = A.head;
    node *q = B.head;
    Set C({}, 0);

    if(p->val < q->val){
        C.head = C.tail = p;
        p = p->next;
        C.tail->next = nullptr;
    }
    else{
        C.head = C.tail = q;
        q = q->next;
        C.tail->next = nullptr;
    }

    while(p && q){
        if(p->val < q->val){
            C.tail->next = p;
            C.tail = p;
            p = p->next;
            C.tail->next = nullptr;
        }
        else{
            C.tail->next = q;
            C.tail = q;
            q = q->next;
            C.tail->next = nullptr;
        }
    }

    if(p){
        C.tail->next = p;
    }
    else{
        C.tail->next = p;
    }
    cout << "\nA merge  B : {";
    C.display(C.head);
    return;
}

void concat()
{
    node *p = A.head;
    while(p->next){
        p = p->next;
    }
    p->next = B.head;

    cout << "A concat B : {";
    A.display(A.head);
    return;
}

int main()
{
    cout << "The sets have been initialized\n\n";
    cout << "Set A : {";
    A.display(A.head);
    cout << "Set B : {";
    B.display(B.head);

    Merge();
    A = Set(arr1, 5);
    B = Set(arr2, 5);
    concat();
    return 0;
}

/*
Set A : {1, 3, 5, 7, 9}
Set B : {1, 2, 3, 4, 5}

A merge  B : {1, 1, 2, 3, 3, 4, 5, 5, 7, 9}
A concat B : {1, 3, 5, 7, 9, 1, 2, 3, 4, 5}
*/
