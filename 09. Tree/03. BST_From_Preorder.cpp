#include <iostream>
#include <stack>

#define INF 10000

using namespace std;

struct node{
    node *lchild;
    int val;
    node *rchild;

    node(int val)
    {
        lchild = nullptr;
        this->val = val;
        rchild = nullptr;
    }
} *root = nullptr;

void create(int *arr, int n)
{
    int i = 0;
    root = new node(arr[i++]);
    node *p = root, *t = nullptr;
    stack <node*> s;

    while(i < n){
        if(arr[i] < p->val){
            t = new node(arr[i++]);
            p->lchild = t;
            s.push(p);
            p = t;
        }
        else{
            if(arr[i] > p->val && arr[i] < (s.empty() ? INF : s.top()->val)){
                t = new node(arr[i++]);
                p->rchild = t;
                p = t;
            }
            else{
                p = s.top();
                s.pop();
            }
        }
    }
    return;
}

void inorder(node *p)
{
    if(p != nullptr){
        inorder(p->lchild);
        cout << " " << p->val;
        inorder(p->rchild);
    }
    return;
}

int main()
{
    int i, n;
    cout << "Number of nodes : ";
    cin >> n;
    int arr[n];

    cout << "Enter pre-order traversal of BST : ";
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }

    create(arr, n);
    cout << "\nIn-order traversal of BST :";
    inorder(root);
    cout << "\n";
    return 0;
}

/*
Number of nodes : 8
Enter pre-order traversal of BST : 30 20 10 15 25 40 50 45

In-order traversal of BST : 10 15 20 25 30 40 45 50
*/
